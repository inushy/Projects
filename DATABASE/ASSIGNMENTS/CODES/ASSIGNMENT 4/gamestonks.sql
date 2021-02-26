/*
    Anushka Verma <Z1911937>
    Database
    Assignment 4
    02/11/2021
*/

drop TABLE IF EXISTS `Receiving`,`Holds`,`Buy/Sell`,`Revenues`,`Deals_With`,`Proceeds`,`Exchange`,`Order`,`Customer_Account`,`Bank_Transactions`,`Bank`,`Stock_Transactions`,`Customer`;

create table `Customer`
(
	`ID`				CHAR(6)		 PRIMARY KEY -- Sets ID as the Primary Key for this table
);
Create Table `Stock_Transactions`
(
	`Symbol`			CHAR(6) 	 PRIMARY KEY, -- Sets SYMBOL as the Primary Key for this table	 
    	`Company_Name`			VARCHAR(30)  NOT NULL,
   	`Amount`			VARCHAR(30)  NOT NULL
);

create table `Bank`
(
	`Account`			VARCHAR(30) PRIMARY KEY, -- Sets ACCOUNT as the Primary Key for this table
    	`Deposit`			INT(255)	NOT NULL,
    	`Withdraw`			INT(255)	NOT NULL
);

create table `Bank_Transactions`
(
	`Credentials`			VARCHAR(30) PRIMARY KEY, -- Sets CREDENTIALS as the Primary Key for this table
    	`Cancelled`			CHAR(20)	NOT NULL,
    	`Approved`			CHAR(20)	NOT NULL,
  	`Pending`			CHAR(20)	NOT NULL
);

create table `Customer_Account`
(
	`Account_Number`		VARCHAR(30) PRIMARY KEY, -- Sets ACCOUNT NUMBER as the Primary Key for this table
    	`Routing_Number`		INT(20)		NOT NULL,
    	`ID`				CHAR(6),
  	 FOREIGN KEY(ID) REFERENCES Customer(ID)
);

create table `Order`
(
	`Order_ID`			VARCHAR(30) PRIMARY KEY, -- Sets ORDER ID as the Primary Key for this table
    	`Buying_Price`			INT(20)		NOT NULL,
    	`Selling_Price`			INT(20)		NOT NULL,
  	`ID`				CHAR(6),
  	 FOREIGN KEY(ID) REFERENCES Customer(ID)
);

create table `Exchange`
(
	`Exchange_ID`			VARCHAR(30) PRIMARY KEY, -- Sets EXCHANGE ID as the Primary Key for this table
  	`Account_Number`		VARCHAR(30)	NOT NULL,
  	 FOREIGN KEY(`Account_Number`) REFERENCES `Customer_Account`(`Account_Number`)
);

create table `Proceeds`
(
	`Account_Number`		VARCHAR(30), 
	`Symbol`			CHAR(6),  
  	`Record`			VARCHAR(255),
  	PRIMARY KEY(`Account_Number`, `Symbol`), -- Sets ACCOUNT NUMBER and SYMBOL as the Primary Key for this table
  	FOREIGN KEY(`Account_Number`) REFERENCES `Customer_Account`(`Account_Number`),
  	FOREIGN KEY(`Symbol`) REFERENCES `Stock_Transactions`(`Symbol`)
);

create table `Deals_With`
(
	`Account_Number`		VARCHAR(30),
	`Account`			VARCHAR(30),	 
  	`Record`			VARCHAR(255),
  	PRIMARY KEY(`Account_Number`, `Account`), -- Sets ACCOUNT NUMBER and ACCOUNT as the Primary Key for this table
  	FOREIGN KEY(`Account_Number`) REFERENCES `Customer_Account`(`Account_Number`),
  	FOREIGN KEY(`Account`) REFERENCES `Bank`(`Account`)
);

create table `Revenues`
(
	`Account`			VARCHAR(30),
	`Credentials`			VARCHAR(30),	 
  	`Record`			VARCHAR(255),
  	PRIMARY KEY(`Account`, `Credentials`), -- Sets ACCOUNT and CREDENTIALS as the Primary Key for this table
  	FOREIGN KEY(`Account`) REFERENCES `Bank`(`Account`),
  	FOREIGN KEY(`Credentials`) REFERENCES `Bank_Transactions`(`Credentials`)
);

create table `Buy/Sell`
(
	`Order_ID`			VARCHAR(30), 
  	`Record`			VARCHAR(255),
  	PRIMARY KEY(`Order_ID`), -- Sets Order ID as the Primary Key for this table
  	FOREIGN KEY(`Order_ID`) REFERENCES `Order`(`Order_ID`)
);

create table `Holds`
(
	`Exchange_ID`			VARCHAR(30),
	`Symbol`			CHAR(6),	 
  	`Record`			VARCHAR(255),
  	PRIMARY KEY(`Exchange_ID`, `Symbol`), -- Sets EXCHANGE ID and SYMBOL as the Primary Key for this table
  	FOREIGN KEY(`Exchange_ID`) REFERENCES `Exchange`(`Exchange_ID`),
  	FOREIGN KEY(`Symbol`) REFERENCES `Stock_Transactions`(`Symbol`)
);

create table `Receiving`
(
	`Order_ID`			VARCHAR(30),
	`Symbol`			CHAR(6),	 
  	`Record`			VARCHAR(255),
  	PRIMARY KEY(`Order_ID`, `Symbol`), -- Sets ORDER ID and SYMBOL as the Primary Key for this table
  	FOREIGN KEY(`Order_ID`) REFERENCES `Order`(`Order_ID`),
  	FOREIGN KEY(`Symbol`) REFERENCES `Stock_Transactions`(`Symbol`)
);
