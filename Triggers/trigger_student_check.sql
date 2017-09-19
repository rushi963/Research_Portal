CREATE OR REPLACE FUNCTION researchportal.student_delete_check()
  RETURNS trigger AS
$BODY$
    BEGIN
        IF (TG_OP = 'DELETE')THEN
		DELETE FROM research_contribution WHERE author_id = OLD.sid ;				
	ELSIF (TG_OP = 'UPDATE') THEN
		UPDATE research_contribution SET author_id = NEW.sid WHERE author_id = OLD.sid;
        END IF;
        RETURN NEW;
    END;
$BODY$
LANGUAGE plpgsql;

set search_path to researchportal;
CREATE TRIGGER student_delete_check
AFTER DELETE OR UPDATE ON student
FOR EACH ROW
EXECUTE PROCEDURE student_delete_check();

