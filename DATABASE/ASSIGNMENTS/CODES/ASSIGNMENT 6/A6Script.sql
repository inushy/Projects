/*
    Anushka Verma <Z1911937>
    Database
    Assignment 6
    02/23/2021
*/

DROP TABLE IF EXISTS Visit, Dog;                                -- CLEARS ALL OF THE TABLES CREATED BELOW (STEP 1)

CREATE TABLE Dog                                                -- CREATES THE DOG TABLE (STEP 2)
(
    dogID       INT NOT NULL AUTO_INCREMENT  PRIMARY KEY,       -- DOGID IS A PRIMARY KEY AS WELL AS AN AUTO INCREMENT
    breed       VARCHAR(230) NOT NULL,                          -- THE KIND OF BREED THE DOG IS
    dogName     VARCHAR(230) NOT NULL,                          -- THE DOG'S NAME
    dogWeight   DECIMAL(5,2) NOT NULL                           -- THE DOG'S WEIGHT
);

INSERT INTO Dog                                                 -- PUTTING SIX ROWS IN OUR DOG TABLE (STEP 3)
    (breed, dogName, dogWeight)
    VALUES('Bulldog', 'Alex', 51),                              -- HERE WE INPUT THE BREED, THE DOG'S NAME, AND THE DOG'S WEIGHT
          ('Bolognese', 'Bella', 6),
          ('Beaglier', 'Milo', 10),
          ('English_Cocker_Spaniel', 'Lucky', 29),
          ('Golden_Retriever', 'Schotzy', 67),
          ('Promeranian', 'Mia', 5);

DESCRIBE Dog;                                                   -- RUN'S THE COMMAND DESCRIBE DOG (STEP 4)

SELECT * FROM Dog;                                              -- RUN'S THE COMMAND SELECT * FROM DOG (STEP 5)

CREATE TABLE Visit                                              -- CREATES THE VISIT TABLE (STEP 6)
(
    visitID        INT  NOT NULL AUTO_INCREMENT  PRIMARY KEY,   -- VISITID IS A PRIMARY KEY AS WELL AS AN AUTO INCREMENT
    dogID          INT  NOT NULL,                               -- THE DOG'S ID
    visitDate      DATETIME NOT NULL,                           -- THE DATE AND TIME THE DOG VISITED
    Lasted         TIME NOT NULL,                               -- HOW LONG DID THE DOG VISIT FOR

    FOREIGN KEY(dogID) REFERENCES Dog(dogID)                    -- DOGID IS OUR FORIEGN KEY SINCE WE ARE REFERING TO OUR DOG TABLE
);  

INSERT INTO Visit                                               -- PUTTING NINE ROWS IN OUR VISIT TABLE (STEP 7)
    (dogID, visitDate, Lasted)                                  -- HERE WE INPUT THE DOG'S ID, THEIR VISIT DATE/TIME, AND HOW LONG THEY VISITED FOR (SOME VISITED MULTIPLE TIMES)
    VALUES(1, '2021-02-23 11:36:00', '01:00:00'),
          (1, '2021-03-14 12:00:00', '01:00:00'),
          (2, '2021-04-20 01:36:00', '02:30:00'),
          (2, '2021-05-09 12:00:00', '02:30:00'),
          (3, '2021-06-12 01:36:00', '00:30:00'),
          (3, '2021-06-20 04:00:00', '00:30:00'),
          (4, '2021-07-18 03:05:00', '02:00:00'),
          (5, '2021-07-25 11:05:00', '01:15:00'),
          (6, '2021-08-01 11:36:00', '01:00:00');

DESCRIBE Visit;                                                 -- RUN'S THE COMMAND DESCRIBE VISIT (STEP 8)

SELECT * FROM Visit;                                            -- RUN'S THE COMMAND SELECT * FROM VISIT (STEP 9)

ALTER TABLE Visit ADD Billing DECIMAL(5,2) NOT NULL;            -- ADDS A COLUMN CALLED BILLING TO THE VISIT TABLE (STEP 10)

UPDATE Visit                                                    -- UPDATES THE ATTRIBUTE IN EXISTING ROWS  (STEP 11)
    SET Billing = 45
    WHERE visitID = 1;

UPDATE Visit
    SET Billing = 45
    WHERE visitID = 2;

UPDATE Visit
    SET Billing = 55
    WHERE visitID = 3;

UPDATE Visit
    SET Billing = 55
    WHERE visitID = 4;

UPDATE Visit
    SET Billing = 20
    WHERE visitID = 5;

UPDATE Visit
    SET Billing = 20
    WHERE visitID = 6;

UPDATE Visit
    SET Billing = 50
    WHERE visitID = 7;

UPDATE Visit
    SET Billing = 48
    WHERE visitID = 8;

UPDATE Visit
    SET Billing = 45
    WHERE visitID = 9;

SELECT *FROM Visit;                                         -- RUN'S THE COMMAND SELECT * FROM VISIT AGAIN (STEP 12)