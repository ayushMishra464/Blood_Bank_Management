CREATE TABLE Donor (
    DonorID NUMBER PRIMARY KEY,
    FirstName VARCHAR2(50) NOT NULL,
    LastName VARCHAR2(50) NOT NULL,
    Gender VARCHAR2(10),
    DateOfBirth DATE,
    BloodType VARCHAR2(5),
    ContactNumber VARCHAR2(15),
    Email VARCHAR2(100),
    Address VARCHAR2(255)
);

CREATE TABLE Donation_ (
    DonationID varchar2(20) PRIMARY KEY,
    DonorID varchar2(20) REFERENCES Donor(DonorID),
    DonationDate DATE,
    BloodType VARCHAR2(5),
    QuantityIn_Ml NUMBER,
    StaffID varchar2(20) REFERENCES Staff(StaffID)
);


CREATE TABLE Recipient (
    RecipientID NUMBER PRIMARY KEY,
    FirstName VARCHAR2(50) NOT NULL,
    LastName VARCHAR2(50) NOT NULL,
    Gender VARCHAR2(10),
    DateOfBirth DATE,
    BloodType VARCHAR2(5),
    QUANITY_GIVEN NUMBER,
    ContactNumber VARCHAR2(15),
    Email VARCHAR2(100),
    Address VARCHAR2(255)
);

CREATE TABLE Staff (
    StaffID NUMBER PRIMARY KEY,
    FirstName VARCHAR2(50) NOT NULL,
    LastName VARCHAR2(50) NOT NULL,
    Gender VARCHAR2(10),
    DateOfBirth DATE,
    J_position VARCHAR2(50),
    ContactNumber VARCHAR2(15),
    Email VARCHAR2(100),
    Address VARCHAR2(255)
);

--TRIGGER(T_BLOOD_STOCK) USED FOR UPDATING THIS
CREATE TABLE BloodBank_Stock (
    BloodType VARCHAR2(5) PRIMARY KEY,
    QuantityIn_ml NUMBER
);

--PACKAGE SPECIFICATION
CREATE OR REPLACE PACKAGE Blood_donation AS
PROCEDURE AddDonor(
    p_FirstName Donor.firstname%type,
    p_LastName Donor.lastname%type,
    p_Gender Donor.gender%TYPE,
    p_DateOfBirth DATE,
    p_BloodType Donor.bloodtype%TYPE,
    p_ContactNumber Donor.contactnumber%TYPE,
    p_Email Donor.email%TYPE,
    p_Address Donor.address%TYPE
);

PROCEDURE AddDonation(
    p_DonorID NUMBER,
    p_DonationDate DATE,
    p_BloodType VARCHAR2,
    p_QuantityIn_ml NUMBER,
    p_StaffID NUMBER
);

PROCEDURE AddRecipient (
    p_FirstName VARCHAR2,
    p_LastName VARCHAR2 ,
    p_Gender VARCHAR2,
    p_DateOfBirth DATE,
    p_BloodType VARCHAR2,
    P_QUANTITY_GIVEN NUMBER,
    p_ContactNumber VARCHAR2,
    p_Email VARCHAR2,
    p_Address VARCHAR2
);

 PROCEDURE Update_BloodStock (
    p_BloodType VARCHAR2,
    p_Quantity INT
);

PROCEDURE Add_staff(
    p_FirstName VARCHAR2 ,
    p_LastName VARCHAR2,
    p_Gender VARCHAR2,
    p_DateOfBirth DATE,
    p_J_position VARCHAR2,
    p_ContactNumber VARCHAR2,
    p_Email VARCHAR2,
    p_Address VARCHAR2 
);

PROCEDURE trigger_fired(BLOODTYPE VARCHAR2,QUANTITYIN_ML NUMBER);

END BLOOD_DONATION;

--SEQUENCES NEEDED FOR PACKAGE BODY
CREATE SEQUENCE donar_seq
  MINVALUE  1
  MAXVALUE 2000
  START WITH 1
  INCREMENT BY 1
  CACHE 20;

DROP SEQUENCE STAFF_seq
  
CREATE SEQUENCE donation_seq
  MINVALUE  1
  MAXVALUE 2000
  START WITH 1
  INCREMENT BY 1
  CACHE 20;

CREATE SEQUENCE recipient_seq
  MINVALUE  1
  MAXVALUE 2000
  START WITH 1
  INCREMENT BY 1
  CACHE 20;
  
CREATE SEQUENCE staff_seq
  MINVALUE  1
  MAXVALUE 2000
  START WITH 1
  INCREMENT BY 1
  CACHE 20;
  
--PACKAGE BODY
CREATE OR REPLACE PACKAGE BODY BLOOD_DONATION AS
PROCEDURE AddDonor(
    p_FirstName Donor.firstname%type,
    p_LastName Donor.lastname%type,
    p_Gender Donor.gender%TYPE,
    p_DateOfBirth DATE,
    p_BloodType Donor.bloodtype%TYPE,
    p_ContactNumber Donor.contactnumber%TYPE,
    p_Email Donor.email%TYPE,
    p_Address Donor.address%TYPE
) IS 
BEGIN
INSERT INTO DONOR VALUES('DONO'|| TO_CHAR(donar_seq.nextval), p_FirstName, p_LastName , 
p_Gender , p_DateOfBirth , p_BloodType,p_ContactNumber ,p_Email ,p_Address);
END ADDDONOR;

PROCEDURE AddDonation(
    p_DonorID VARCHAR2,
    p_DonationDate DATE,
    p_BloodType VARCHAR2,
    p_QuantityIn_ml NUMBER,
    p_StaffID VARCHAR2
) IS
BEGIN
INSERT INTO DONATION_ VALUES('DONA'||TO_CHAR(donation_seq.nextval),p_DonorID,p_DonationDate,
p_BloodType ,p_QuantityIn_ml ,p_StaffID );
END ADDDONATION;

PROCEDURE AddRecipient (
    p_FirstName VARCHAR2,
    p_LastName VARCHAR2 ,
    p_Gender VARCHAR2,
    p_DateOfBirth DATE,
    p_BloodType VARCHAR2,
    P_QUANTITY_GIVEN NUMBER,
    p_ContactNumber VARCHAR2,
    p_Email VARCHAR2,
    p_Address VARCHAR2
) IS 
BEGIN
INSERT INTO RECIPIENT VALUES('REC' || TO_CHAR(RECIPIENT_SEQ.NEXTVAL), p_FirstName,p_LastName  ,
p_Gender ,p_DateOfBirth ,p_BloodType ,P_QUANTITY_GIVEN,p_ContactNumber ,p_Email ,p_Address );
END ADDRECIPIENT;

PROCEDURE Update_BloodStock_ (
    p_BloodType VARCHAR2,
    p_Quantity INT
)IS 
BEGIN 
CASE p_BloodType
WHEN 'A+' THEN
UPDATE BLOODBANK_STOCK
SET BLOODBANK_STOCK.QuantityIn_ml= BLOODBANK_STOCK.QuantityIn_ml + P_QUANTITY
WHERE BLOODBANK_STOCK.BLOODTYPE= 'A+';

WHEN 'B+' THEN
UPDATE BLOODBANK_STOCK
SET BLOODBANK_STOCK.QuantityIn_ml= BLOODBANK_STOCK.QuantityIn_ml + P_QUANTITY
WHERE BLOODBANK_STOCK.BLOODTYPE= 'B+';

WHEN 'O+' THEN
UPDATE BLOODBANK_STOCK
SET BLOODBANK_STOCK.QuantityIn_ml= BLOODBANK_STOCK.QuantityIn_ml + P_QUANTITY
WHERE BLOODBANK_STOCK.BLOODTYPE= 'O+';

WHEN 'A-' THEN
UPDATE BLOODBANK_STOCK
SET BLOODBANK_STOCK.QuantityIn_ml= BLOODBANK_STOCK.QuantityIn_ml + P_QUANTITY
WHERE BLOODBANK_STOCK.BLOODTYPE= 'A-';

WHEN 'B-' THEN
UPDATE BLOODBANK_STOCK
SET BLOODBANK_STOCK.QuantityIn_ml= BLOODBANK_STOCK.QuantityIn_ml + P_QUANTITY
WHERE BLOODBANK_STOCK.BLOODTYPE= 'B-';

WHEN 'O-' THEN
UPDATE BLOODBANK_STOCK
SET BLOODBANK_STOCK.QuantityIn_ml= BLOODBANK_STOCK.QuantityIn_ml + P_QUANTITY
WHERE BLOODBANK_STOCK.BLOODTYPE= 'O-';

WHEN 'AB+' THEN
UPDATE BLOODBANK_STOCK
SET BLOODBANK_STOCK.QuantityIn_ml= BLOODBANK_STOCK.QuantityIn_ml + P_QUANTITY
WHERE BLOODBANK_STOCK.BLOODTYPE= 'AB+';

WHEN 'AB-' THEN
UPDATE BLOODBANK_STOCK
SET BLOODBANK_STOCK.QuantityIn_ml= BLOODBANK_STOCK.QuantityIn_ml + P_QUANTITY
WHERE BLOODBANK_STOCK.BLOODTYPE= 'AB-';
END CASE;
END UPDATE_BLOODSTOCK;

PROCEDURE Add_staff(
    p_FirstName VARCHAR2 ,
    p_LastName VARCHAR2,
    p_Gender VARCHAR2,
    p_DateOfBirth DATE,
    p_J_position VARCHAR2,
    p_ContactNumber VARCHAR2,
    p_Email VARCHAR2,
    p_Address VARCHAR2 
)IS
BEGIN
INSERT INTO STAFF VALUES('STF'||TO_CHAR(staff_seq.nextval), p_FirstName ,p_LastName,p_Gender,
p_DateOfBirth,p_J_position ,p_ContactNumber ,p_Email,p_Address);
END ADD_STAFF;

PROCEDURE trigger_fired (BLOODTYPE VARCHAR2,QUANTITYIN_ML NUMBER)IS
BEGIN
BLOOD_DONATION.UPDATE_BLOODSTOCK_ADD(BLOODTYPE,QUANTITYIN_ML);
END trigger_fired;

END BLOOD_DONATION;

--TO ADD DONOR
DECLARE 
    p_FirstName Donor.firstname%type:= '&FIRST_NAME';
    p_LastName Donor.lastname%type:='&LAST_NAME';
    p_Gender Donor.gender%TYPE:='&GENDER';
    p_DateOfBirth DATE:=DATE '&DATE_OF_BIRTH';
    p_BloodType Donor.bloodtype%TYPE :='&BLOOD_TYPE';
    p_ContactNumber Donor.contactnumber%TYPE := &PHONE_NUMBER;
    p_Email Donor.email%TYPE:='&EMAIL_ID';
    p_Address Donor.address%TYPE:='&ADDRESS';
BEGIN
BLOOD_DONATION.ADDdonor( p_FirstName,p_LastName ,p_Gender,p_DateOfBirth , p_BloodType ,
    p_ContactNumber ,p_Email,p_Address);
end;

--TO ADD DONATION
DECLARE
    p_DonorID VARCHAR2(50) := '&DONOR_ID';
    p_DonationDate DATE := TO_DATE('&DONATION_DATE', 'YYYY-MM-DD');
    p_BloodType VARCHAR2(10) := '&BLOOD_TYPE';
    p_QuantityIn_ml NUMBER := &QUANTITY_IN_ML;
    p_StaffID VARCHAR2(50) := '&STAFF_ID';
BEGIN
    BLOOD_DONATION.adddonation(
        p_DonorID,
        p_DonationDate,
        p_BloodType,
        p_QuantityIn_ml,
        p_StaffID
    );
    BLOOD_DONATION.TRIGGER_FIRED( p_BloodType,p_QuantityIn_ml);
END;


--TO ADD RECIPIENT
DECLARE
    p_FirstName VARCHAR2(20) := '&FIRST_NAME';
    p_LastName VARCHAR2(20):='&LAST_NAME';
    p_Gender VARCHAR2(20):='&GENDER';
    p_DateOfBirth DATE := DATE '&DATE_OF_BIRTH';
    p_BloodType VARCHAR2(20):= '&BLOOD_TYPE';
    P_QUANTITY_GIVEN NUMBER := &QUANTITY_GIVEN;
    p_ContactNumber NUMBER:=&PHONE_NUMBER;
    p_Email VARCHAR2(20):='&EMAIL';
    p_Address VARCHAR2(20):='&ADDRESS';
BEGIN
blood_donation.addrecipient(p_FirstName , p_LastName , p_Gender , p_DateOfBirth ,
    p_BloodType,P_QUANTITY_GIVEN,p_ContactNumber ,p_Email ,p_Address);
END;

--TO ADD BLOOD IN STOCK
CREATE OR REPLACE TRIGGER T_BLOOD_STOCK_A
AFTER
INSERT ON DONATION_
FOR EACH ROW
BEGIN 
BLOOD_DONATION.UPDATE_BLOODSTOCK_ADD(:NEW.BLOODTYPE,:NEW.QUANTITYIN_ML);
end;

--TO DEDUCT BLOOD FROM STOCK
CREATE OR REPLACE TRIGGER T_BLOOD_STOCK_D
AFTER
INSERT ON RECIPIENT
FOR EACH ROW
BEGIN 
BLOOD_DONATION.UPDATE_BLOODSTOCK_DEDUCT(:NEW.BLOODTYPE,:NEW.QUANTITY_GIVEN);
end;

--TO ADD NEW STAFF
DECLARE
    p_FirstName VARCHAR2(50):='&FIRST_NAME' ;
    p_LastName VARCHAR2(50):='&LAST_NAME';
    p_Gender VARCHAR2(50):='GENDER';
    p_DateOfBirth DATE:=DATE '&DATE_OF_BIRTH';
    p_J_position VARCHAR2(50):='&JOB';
    p_ContactNumber VARCHAR2(50):=&NUMBER_;
    p_Email VARCHAR2(50):='&EMAIL';
    p_Address VARCHAR2(50):='&ADDRESS';
BEGIN
BLOOD_DONATION.ADD_STAFF( p_FirstName , p_LastName , p_Gender , p_DateOfBirth ,p_J_position ,
    p_ContactNumber ,p_Email ,p_Address);
END;















