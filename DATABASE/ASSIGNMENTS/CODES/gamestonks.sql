/*
    Anushka Verma <Z1911937>
    Database
    Assignment 4
    02/11/2021
*/

drop TABLE IF EXISTS `Receiving`,`Holds`,`Buy/Sell`,`Revenues`,`Deals_With`,`Proceeds`,`Exchange`,`Order`,`Customer_Account`,`Bank_Transactions`,`Bank`,`Stock_Transactions`,`Customer`;

create table `Customer`
(
	`ID`				char(6)		 PRIMARY KEY -- Sets ID as the Primary Key for this table
);
Create Table `Stock_Transactions`
(
	`Symbol`			char(6) 	 PRIMARY KEY, -- Sets SYMBOL as the Primary Key for this table	 
    `Company_Name`		VARCHAR(30)  NOT NULL,
    `Amount`			VARCHAR(30)	 nOT NULL
);

create table `Bank`
(
	`Account`			Varchar(30) PRIMARY KEY, -- Sets ACCOUNT as the Primary Key for this table
    `Deposit`			INT(255)	NOT NULL,
    `Withdraw`			int(255)	NOT NULL
);

create table `Bank_Transactions`
(
	`Credentials`		Varchar(30) PRIMARY KEY, -- Sets CREDENTIALS as the Primary Key for this table
    `Cancelled`			char(20)	NOT NULL,
    `Approved`			char(20)	NOT NULL,
  	`Pending`			char(20)	not NULL
);

create table `Customer_Account`
(
	`Account_Number`	varchar(30) PRIMARY KEY, -- Sets ACCOUNT NUMBER as the Primary Key for this table
    `Routing_Number`	INT(20)		NOT NULL,
    `ID`				char(6),
  	 foreign key(ID) references Customer(ID)
);

create table `Order`
(
	`Order_ID`			Varchar(30) PRIMARY KEY, -- Sets ORDER ID as the Primary Key for this table
    `Buying_Price`		INT(20)		NOT NULL,
    `Selling_Price`		INT(20)		NOT NULL,
  	`ID`				CHAR(6),
  	 foreign key(ID) references Customer(ID)
);

create table `Exchange`
(
	`Exchange_ID`		Varchar(30) PRIMARY KEY, -- Sets EXCHANGE ID as the Primary Key for this table
  	`Account_Number`	varchar(30)	not NULL,
  	 foreign key(`Account_Number`) references `Customer_Account`(`Account_Number`)
);

create table `Proceeds`
(
	`Account_Number`	varchar(30), 
	`Symbol`			char(6),  
  	`Record`			VARCHAR(255),
  	primary key(`Account_Number`, `Symbol`), -- Sets ACCOUNT NUMBER and SYMBOL as the Primary Key for this table
  	Foreign key(`Account_Number`) REFERENCES `Customer_Account`(`Account_Number`),
  	Foreign key(`Symbol`) REFERENCES `Stock_Transactions`(`Symbol`)
);

create table `Deals_With`
(
	`Account_Number`	varchar(30),
	`Account`			Varchar(30),	 
  	`Record`			VARCHAR(255),
  	primary key(`Account_Number`, `Account`), -- Sets ACCOUNT NUMBER and ACCOUNT as the Primary Key for this table
  	Foreign key(`Account_Number`) REFERENCES `Customer_Account`(`Account_Number`),
  	Foreign key(`Account`) REFERENCES `Bank`(`Account`)
);

create table `Revenues`
(
	`Account`			varchar(30),
	`Credentials`		Varchar(30),	 
  	`Record`			VARCHAR(255),
  	primary key(`Account`, `Credentials`), -- Sets ACCOUNT and CREDENTIALS as the Primary Key for this table
  	Foreign key(`Account`) REFERENCES `Bank`(`Account`),
  	Foreign key(`Credentials`) REFERENCES `Bank_Transactions`(`Credentials`)
);

create table `Buy/Sell`
(
	`Order_ID`			varchar(30), 
  	`Record`			VARCHAR(255),
  	primary key(`Order_ID`), -- Sets Order ID as the Primary Key for this table
  	Foreign key(`Order_ID`) REFERENCES `Order`(`Order_ID`)
);

create table `Holds`
(
	`Exchange_ID`		varchar(30),
	`Symbol`			char(6),	 
  	`Record`			VARCHAR(255),
  	primary key(`Exchange_ID`, `Symbol`), -- Sets EXCHANGE ID and SYMBOL as the Primary Key for this table
  	Foreign key(`Exchange_ID`) REFERENCES `Exchange`(`Exchange_ID`),
  	Foreign key(`Symbol`) REFERENCES `Stock_Transactions`(`Symbol`)
);

create table `Receiving`
(
	`Order_ID`			varchar(30),
	`Symbol`			char(6),	 
  	`Record`			VARCHAR(255),
  	primary key(`Order_ID`, `Symbol`), -- Sets ORDER ID and SYMBOL as the Primary Key for this table
  	Foreign key(`Order_ID`) REFERENCES `Order`(`Order_ID`),
  	Foreign key(`Symbol`) REFERENCES `Stock_Transactions`(`Symbol`)
);