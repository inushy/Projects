/* Anushka Verma, Aby Shulgan, Vansh Rai, Vlad Oprescu
   Database
   2A2V - Group project final
   CSCI 466-1
   04/21/2021
*/

DROP TABLE IF EXISTS PriorityQueue;							 -- CLEARS ALL OF THE TABLES CREATED BELOW
DROP TABLE IF EXISTS FreeQueue;								 -- 		     |
DROP TABLE IF EXISTS Participants;							 -- 		     |
DROP TABLE IF EXISTS KaraokeVersions;						 	 -- 		     |
DROP TABLE IF EXISTS SongContributions;						 	 -- 		     |
DROP TABLE IF EXISTS Contributors;							 -- 		     |
DROP TABLE IF EXISTS Songs;								 -- 		     V

CREATE TABLE Songs(									 -- CREATES THE SONGS TABLE
	ID		int	PRIMARY KEY AUTO_INCREMENT NOT NULL,		         -- ID IS A PRIMARY KEY AS WELL AS AN AUTO INCREMENT
	title		varchar(255) NOT NULL,						 -- SONGS TITLE
	artist		varchar(255) NOT NULL						 -- THE ARTIST(S) PART SONG
);

CREATE TABLE Contributors(							         -- CREATES THE CONTRIBUTORS TABLE
	ID		int	PRIMARY KEY AUTO_INCREMENT NOT NULL,		         -- ID IS A PRIMARY KEY AS WELL AS AN AUTO INCREMENT
	name		varchar(255) NOT NULL,						 -- CONTRIBUTORS TITLE
	type		varchar(255) NOT NULL						 -- CONTRIBUTOR TYPE
);

CREATE TABLE SongContributions(								 -- CREATES THE SONG CONTRIBUTIONS TABLE
	ID		int	PRIMARY KEY AUTO_INCREMENT NOT NULL,		         -- ID IS A PRIMARY KEY AS WELL AS AN AUTO INCREMENT
	songID		int	NOT NULL,						 -- SONG'S ID
	contributorID	int	NOT NULL,					         -- CONTRIBUTOR'S TITLE

	FOREIGN KEY (songID) REFERENCES Songs(ID),				         -- SONGID IS OUR FORIEGN KEY SINCE WE ARE REFERING TO OUR SONGS TABLE
	FOREIGN KEY (contributorID) REFERENCES Contributors(ID)	                         -- CONTRIBUTORID IS OUR FORIEGN KEY SINCE WE ARE REFERING TO OUR CONTRIBUTORS TABLE
);

CREATE TABLE KaraokeVersions(								 -- CREATES THE KARAOKE VERSIONS TABLE
	fileID		int	PRIMARY KEY AUTO_INCREMENT NOT NULL,	                 -- FILEID IS A PRIMARY KEY AS WELL AS AN AUTO INCREMENT
	version		varchar(255) NOT NULL,						 -- KARAOKE VERSION
	songID		int,							         -- SONG'S ID

	FOREIGN KEY (songID) REFERENCES Songs(ID)				         -- SONGID IS OUR FORIEGN KEY SINCE WE ARE REFERING TO OUR SONGS TABLE
);

CREATE TABLE Participants(								 -- CREATES THE PARTICIPANTS TABLE
	ID		int	PRIMARY KEY AUTO_INCREMENT NOT NULL,		         -- ID IS A PRIMARY KEY AS WELL AS AN AUTO INCREMENT
	firstName	varchar(255) NOT NULL,						 -- PARTICIPANT'S FIRST NAME
	lastName	varchar(255) NOT NULL						 -- PARTICIPANT'S LAST NAME
);

CREATE TABLE FreeQueue(								         -- CREATES THE FREE QUEUE TABLE
	ID		int	PRIMARY KEY AUTO_INCREMENT NOT NULL,		         -- ID IS A PRIMARY KEY AS WELL AS AN AUTO INCREMENT
	time	time NOT NULL,							         -- TIME THE QUEUE WAS ENTERED
	participantID	int	NOT NULL,					         -- PARTICIPANT'S ID
	fileID		int	NOT NULL,						 -- FILE ID OF THE KARAOKE SONG

	FOREIGN KEY (participantID) REFERENCES Participants(ID),                         -- PARTICIPANTID IS OUR FORIEGN KEY SINCE WE ARE REFERING TO OUR PARTICIPANTS TABLE
	FOREIGN KEY (fileID) REFERENCES KaraokeVersions(fileID)	                         -- FILEID IS OUR FORIEGN KEY SINCE WE ARE REFERING TO OUR KARAOKEVERSIONS TABLE
);

CREATE TABLE PriorityQueue(							         -- CREATES THE PRIORITY QUEUE TABLE
	ID		int	PRIMARY KEY AUTO_INCREMENT NOT NULL,		         -- ID IS A PRIMARY KEY AS WELL AS AN AUTO INCREMENT
	time		time	NOT NULL,						 -- TIME THE QUEUE WAS ENTERED
	participantID	int	NOT NULL,						 -- PARTICIPANT'S ID
	fileID		int	NOT NULL,						 -- FILE ID OF THE KARAOKE SONG
	paidAmount	DECIMAL (5, 2), 						 -- THE AMOUNT PAID BY THE PARTICIPANT

	FOREIGN KEY (participantID) REFERENCES Participants(ID), 			 -- PARTICIPANTID IS OUR FORIEGN KEY SINCE WE ARE REFERING TO OUR PARTICIPANTS TABLE
	FOREIGN KEY (fileID) REFERENCES KaraokeVersions(fileID)  			 -- FILEID IS OUR FORIEGN KEY SINCE WE ARE REFERING TO OUR KARAOKEVERSIONS TABLE
);

