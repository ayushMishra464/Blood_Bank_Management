# Blood Donation Management System

## Overview
The Blood Donation Management System is designed to facilitate efficient management of blood donors, donations, recipients, staff, and blood bank stock. It consists of a comprehensive SQL schema, Power BI dashboards for data visualization, and an ER diagram for database structure visualization. This README file provides an overview of the SQL project, the Power BI dashboard, and the ER diagram.

## Components

### 1. SQL Project

#### Database Schema

- **Donor Table**
  - Columns:
    - DonorID (NUMBER, Primary Key)
    - FirstName (VARCHAR2(50), Not Null)
    - LastName (VARCHAR2(50), Not Null)
    - Gender (VARCHAR2(10))
    - DateOfBirth (DATE)
    - BloodType (VARCHAR2(5))
    - ContactNumber (VARCHAR2(15))
    - Email (VARCHAR2(100))
    - Address (VARCHAR2(255))

- **Donation_ Table**
  - Columns:
    - DonationID (VARCHAR2(20), Primary Key)
    - DonorID (VARCHAR2(20), Foreign Key References Donor(DonorID))
    - DonationDate (DATE)
    - BloodType (VARCHAR2(5))
    - QuantityIn_Ml (NUMBER)
    - StaffID (VARCHAR2(20), Foreign Key References Staff(StaffID))

- **Recipient Table**
  - Columns:
    - RecipientID (NUMBER, Primary Key)
    - FirstName (VARCHAR2(50), Not Null)
    - LastName (VARCHAR2(50), Not Null)
    - Gender (VARCHAR2(10))
    - DateOfBirth (DATE)
    - BloodType (VARCHAR2(5))
    - QuantityGiven (NUMBER)
    - ContactNumber (VARCHAR2(15))
    - Email (VARCHAR2(100))
    - Address (VARCHAR2(255))

- **Staff Table**
  - Columns:
    - StaffID (NUMBER, Primary Key)
    - FirstName (VARCHAR2(50), Not Null)
    - LastName (VARCHAR2(50), Not Null)
    - Gender (VARCHAR2(10))
    - DateOfBirth (DATE)
    - Position (VARCHAR2(50))
    - ContactNumber (VARCHAR2(15))
    - Email (VARCHAR2(100))
    - Address (VARCHAR2(255))

- **BloodBank_Stock Table**
  - Columns:
    - BloodType (VARCHAR2(5), Primary Key)
    - QuantityIn_ml (NUMBER)

#### Sequences

- **donor_seq**
- **donation_seq**
- **recipient_seq**
- **staff_seq**

#### Package: Blood_donation

- **Procedures:**
  - AddDonor
  - AddDonation
  - AddRecipient
  - Update_BloodStock
  - Add_staff
  - trigger_fired

#### Triggers

- **T_BLOOD_STOCK_A**
  - Triggered after an insert on the Donation_ table to update blood stock by adding the donated quantity.

- **T_BLOOD_STOCK_D**
  - Triggered after an insert on the Recipient table to update blood stock by deducting the given quantity.

### 2. Power BI Dashboard

The Power BI dashboard provides a visual representation of the blood donation data across various blood banks in India. The data is sourced from the Indian government and includes the following visualizations:

- **Blood Bank Locations:**
  - Map visualization showing the geographic distribution of blood banks across India.
  
- **Blood Stock Levels:**
  - Bar and line charts representing the quantity of different blood types available across blood banks.
  
- **Donor and Recipient Statistics:**
  - Pie charts and tables displaying the number of donors, recipients, and the amount of blood donated and received.

- **Overall Blood Bank Data:**
  - A comprehensive overview of blood bank data including the total number of blood banks, available stock, and distribution.

### 3. ER Diagram

The ER diagram provides a visual representation of the database structure, highlighting the relationships between different entities:

- **Entities:**
  - Donor
  - Donation
  - Recipient
  - Staff
  - BloodBank_Stock

- **Relationships:**
  - Donors make Donations.
  - Donations are managed by Staff.
  - Recipients receive blood which affects BloodBank_Stock.
  - BloodBank_Stock tracks the quantity of each blood type.

## Usage Instructions

### SQL Project

#### Adding a Donor
```sql
DECLARE 
    p_FirstName Donor.firstname%type := '&FIRST_NAME';
    p_LastName Donor.lastname%type := '&LAST_NAME';
    p_Gender Donor.gender%TYPE := '&GENDER';
    p_DateOfBirth DATE := DATE '&DATE_OF_BIRTH';
    p_BloodType Donor.bloodtype%TYPE := '&BLOOD_TYPE';
    p_ContactNumber Donor.contactnumber%TYPE := &PHONE_NUMBER;
    p_Email Donor.email%TYPE := '&EMAIL_ID';
    p_Address Donor.address%TYPE := '&ADDRESS';
BEGIN
BLOOD_DONATION.ADDdonor(p_FirstName, p_LastName, p_Gender, p_DateOfBirth, p_BloodType,
    p_ContactNumber, p_Email, p_Address);
END;
```

#### Adding a Donation
```sql
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
    BLOOD_DONATION.TRIGGER_FIRED(p_BloodType, p_QuantityIn_ml);
END;
```

#### Adding a Recipient
```sql
DECLARE
    p_FirstName VARCHAR2(20) := '&FIRST_NAME';
    p_LastName VARCHAR2(20) := '&LAST_NAME';
    p_Gender VARCHAR2(20) := '&GENDER';
    p_DateOfBirth DATE := DATE '&DATE_OF_BIRTH';
    p_BloodType VARCHAR2(20) := '&BLOOD_TYPE';
    P_QUANTITY_GIVEN NUMBER := &QUANTITY_GIVEN;
    p_ContactNumber NUMBER := &PHONE_NUMBER;
    p_Email VARCHAR2(20) := '&EMAIL';
    p_Address VARCHAR2(20) := '&ADDRESS';
BEGIN
blood_donation.addrecipient(p_FirstName, p_LastName, p_Gender, p_DateOfBirth,
    p_BloodType, P_QUANTITY_GIVEN, p_ContactNumber, p_Email, p_Address);
END;
```

#### Adding New Staff
```sql
DECLARE
    p_FirstName VARCHAR2(50) := '&FIRST_NAME';
    p_LastName VARCHAR2(50) := '&LAST_NAME';
    p_Gender VARCHAR2(50) := 'GENDER';
    p_DateOfBirth DATE := DATE '&DATE_OF_BIRTH';
    p_J_position VARCHAR2(50) := '&JOB';
    p_ContactNumber VARCHAR2(50) := &NUMBER_;
    p_Email VARCHAR2(50) := '&EMAIL';
    p_Address VARCHAR2(50) := '&ADDRESS';
BEGIN
BLOOD_DONATION.ADD_STAFF(p_FirstName, p_LastName, p_Gender, p_DateOfBirth, p_J_position,
    p_ContactNumber, p_Email, p_Address);
END;
```

### Power BI Dashboard

1. Open the Power BI dashboard file using Power BI Desktop.
2. Explore the various visualizations:
    - **Maps** for blood bank locations across India.
    - **Bar charts** for blood stock levels by blood type.
    - **Pie charts and tables** for donor and recipient statistics.
    - **Comprehensive overviews** of blood bank data, including total blood banks and available stock.
3. Use the filters and slicers to customize the data view according to specific needs.

### ER Diagram

1. Open the ER diagram file using any compatible ER diagram viewer or drawing tool.
2. Review the entities and relationships to understand the database structure.
3. Use the ER diagram as a reference for understanding how different tables in the SQL project are related.

## Conclusion
This Blood Donation Management System provides a comprehensive solution for managing blood donations, recipients, and stock levels. The SQL project defines the database schema and procedures, the Power BI dashboard offers insightful visualizations of blood banks across India, and the ER diagram presents a clear view of the database structure. Collectively, these components ensure efficient and effective management of blood donation activities.
