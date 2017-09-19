CREATE OR REPLACE FUNCTION researchportal.prof_delete_check()
  RETURNS trigger AS
$BODY$
    BEGIN
        IF (TG_OP = 'DELETE')THEN
		DELETE FROM research_contribution WHERE author_id = OLD.prof_id ;				
	ELSIF (TG_OP = 'UPDATE') THEN
		UPDATE research_contribution SET author_id = NEW.prof_id WHERE author_id = OLD.prof_id;
        END IF;
        RETURN NEW;
    END;
$BODY$
LANGUAGE plpgsql;

set search_path to researchportal;
CREATE TRIGGER prof_delete_check
AFTER DELETE OR UPDATE ON professor
FOR EACH ROW
EXECUTE PROCEDURE prof_delete_check();

