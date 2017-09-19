CREATE TYPE student_name AS (st_name character varying (40));

CREATE OR REPLACE FUNCTION researchportal.goodStudentPublishers() RETURNS SETOF student_name AS $BODY$
DECLARE
	s_name student_name;
BEGIN
	FOR s_name IN SELECT sname FROM (SELECT author_id, count(doi) as noOfPublications FROM research_contribution GROUP BY author_id HAVING count(doi)>1) AS r JOIN student AS s ON r.author_id=s.sid
	LOOP
		RETURN NEXT s_name;			
	END LOOP;
	RETURN;
END
$BODY$
LANGUAGE plpgsql;