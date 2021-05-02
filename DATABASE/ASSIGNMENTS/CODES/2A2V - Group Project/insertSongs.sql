/*2a2v - group project final
 CSCI 466-1*/

/*Inserting sample songs*/
INSERT INTO Songs
        (title, artist)
        VALUES
        ('Who Wants to Live Forever', 'Queen'), -- 1
        ('Bohemian Rhapsody', 'Queen'), -- 2
        ('I Want to Break Free', 'Queen'), -- 3
        ('Dont Stop Me Now', 'Queen'), -- 4
        ('Killer Queen', 'Queen'), -- 5
        ('Love of My Life', 'Queen'), -- 6
        ('Somebody to Love', 'Queen'), -- 7
        ('Radio Ga Ga', 'Queen'), -- 8
        ('I Wanna Dance With Somebody', 'Whitney Houston'), -- 9
        ('Dancing Queen', 'ABBA'), -- 10
        ('Believe', 'Cher'), -- 11
        ('DJ Got Us Fallin In Love', 'Usher, Pitbull'), -- 12
        ('Hollaback Girl', 'Gwen Stefani'), -- 13
        ('Baby One More Time', 'Britney Spears'), -- 14
        ('Bye Bye Bye', 'NSYNC'), -- 15
        ('Everybody', 'The Backstreet Boys'), -- 16
        ('FourFiveSeconds','Rihanna, Kanye West, and Paul McCartney'), -- 17
        ('Party In the USA','Miley Cyrus'), -- 18
        ('Wake Me up','Avicii'), -- 19
        ('Livin on a Prayer','Bon Jovi'), -- 20
        ('21 Guns','Green Day'), -- 21
        ('High Hopes','High Hopes Panic! At the Disco'), -- 22
        ('I Need Your Love','Calvin Harris, and Ellie Goulding'), -- 23
        ('24k Magic','Bruno Mars'), -- 24
	('Yeah!','Usher'), -- 25
	('Call Me Maybe','Carly Rae Jepsen'), -- 26
	('Blurred Lines','Robin Thicke'), -- 27
	('Gold Digger','Kamye West'), -- 28
        ('Closer', 'The Chainsmokers'), -- 29
	('I Gotta Feeling', 'Black Eyed Peas'), -- 30
 	('Hawai(Remix)','Maluma'), -- 31
	('Dont You Worry Child','Swedish House Mafia'); -- 32


/*Inserting sample contributors*/
INSERT INTO Contributors(name, type)
	VALUES
	('Brian May', 'Songwriter'), -- 1
        ('David Richards', 'Producer'), -- 2
        ('Freddie Mercury', 'Songwriter'), -- 3
        ('Roy Thomas Baker', 'Producer'), -- 4
        ('John Deacon', 'Songwriter'), -- 5
        ('ReinHold Mack', 'Producer'), -- 6
        ('Roger Taylor', 'Songwriter'), -- 7
        ('Narada Michael Walden', 'Producer'),  -- 8 Anushka's List Starts
        ('George Merrill', 'Songwriter'), -- 9
	('Shannon Rubicam', 'Songwriter'), -- 10
        ('Benny Andersson', 'Songwriter'), -- 11
	('Björn Ulvaeus', 'Songwriter'), -- 12
	('Stig Anderson', 'Songwriter'), -- 13
        ('Benny Andersson', 'Producer'), -- 14
	('Björn Ulvaeus', 'Producer'), -- 15
        ('Brian Higgins', 'Songwriter'), -- 16
	('Stuart McLennen', 'Songwriter'), -- 17
	('Paul Barry', 'Songwriter'), -- 18
	('Steven Torch', 'Songwriter'), -- 19
	('Matthew Gray', 'Songwriter'), -- 20
	('Timothy Powell', 'Songwriter'), -- 21
	('Cher', 'Songwriter'), -- 22
        ('Mark Taylor', 'Producer'), -- 23
	('Brian Rawling', 'Producer'), -- 24
        ('Max Martin', 'Songwriter'), -- 25
	('Shellback', 'Songwriter'), -- 26
	('Savan Kotecha', 'Songwriter'), -- 27
	('Pitbull', 'Songwriter'), -- 28
        ('Max Martin', 'Producer'), -- 29
	('Shellback', 'Producer'), -- 30
        ('Gwen Stefani', 'Songwriter'), -- 31
	('Pharrell Williams', 'Songwriter'), -- 32
	('Chad Hugo', 'Songwriter'), -- 33
        ('The Neptunes', 'Producer'), -- 34
        ('Max Martin', 'Songwriter'), -- 35
        ('Max Martin', 'Producer'), -- 36
	('Rami', 'Songwriter'), -- 37
        ('Kristian Lundin', 'Songwriter'), -- 38
	('Jake Schulze', 'Songwriter'),  -- 39
	('Andreas Carlsson', 'Songwriter'), -- 40
        ('Kristian Lundin', 'Producer'),  -- 41
	('Jake Schulze', 'Producer'), -- 42
        ('Max Martin', 'Songwriter'), -- 43
        ('Denniz Pop', 'Producer'), -- 44
	('Max Martin', 'Producer'),         -- 45 Anushka's List Ends 
        ('Kirby Lauryen', 'Songwriter'),    -- 46 Vansh's List Starts here 
        ('Mike Dean', 'Producer'), -- 47
        ('Lukasz Gottwald', 'Songwriter'), -- 48 
        ('Jessica Cornish', 'Producer'), -- 49
        ('Avicii', 'Producer'),  -- 50
        ('Arash Pournouri', 'Songwriter'), -- 51 
        ('Butch Vig', 'Producer'), -- 52
        ('Billie Joe Armstrong', 'Songwriter'), -- 53
        ('Richie Sambora', 'Producer'), -- 54
        ('Desmond Child', 'Songwriter'), -- 55
        ('Jake Sinclair', 'Producer'),  -- 56
        ('Billie Joe Armstrong', 'Songwriter'), -- 57
        ('Calvin Harris', 'Producer'),      -- 58
        ('Ellie Goulding', 'Songwriter'),   -- 59
        ('Shampoo Press ', 'Producer'),     -- 60
        ('Philip Lawrence', 'Songwriter'),  -- 61 Vansh's ends here 
	('Chrisopher Bridges', 'Songwriter'), -- 62 Vlad's List
	('James Philips','Songwriter'), -- 63
	('Johnatan Smith','Songwriter'), -- 64
	('Patrick Smith','Songwriter'), -- 65
	('Sean Garret','Songwriter'), -- 66
	('Lil Jon','Producer'), -- 67 
	('Carley Rae Jepsen','Songwriter'), -- 68
	('Josh Ramsey','Songwriter'), -- 69
	('Tavish Crowe','Songwriter'), -- 70
	('Carly Rae Jepsen','Producer'), -- 71
	('Robin Thicke','Songwriter'), -- 72
	('Pharell Williams','Songwriter'),  -- 73
	('Clifford Harris Jr','Songwriter'), -- 74
	('Pharell','Producer'), -- 75
	('Marvin Gaye','Songwriter'), -- 76
	('Kanye West','Songwriter'), -- 77
	('Ray Charles','Songwriter'), -- 78
	('Renald Richard','Songwriter'), -- 79
	('Kanye West','Producer'), -- 80
	('John Brion','Producer'), -- 81
	('Andrew Taggart','Songwriter'), -- 82
	('Ashley Frangipane','Songwriter'), -- 83
	('Issac Slade','Songwriter'), -- 84
	('The Chainsmokers','Producers'), -- 85
	('William Adams','Songwriter'), -- 86
	('Stacy Ferguson','Songwriter'), -- 87
	('Jaime Gomez','Songwriter'), -- 88
	('David Guetta','Songwriter'), -- 89
	('David Guetta','Producer'), -- 90 
	('Juan Luis Londono','Songwriter'), -- 91
	('Edgar Barrera','Songwriter'), -- 92
	('Rene Cano','Songwriter'), -- 93
	('Kevin Cruz','Songwriter'), -- 94
	('lly Wonder','Producer'), -- 95
	('Jowan','Producer'), -- 96
	('Keitym','Producer'), -- 97
	('Kevin ADG','Producer'), -- 98
	('Axel Hedfors','Songwriter'), -- 99
	('Steve Angello','Songwriter'), -- 100
	('Sebastian Ingrosso','Songwriter'), -- 101
	('Swedish House Mafia','Producer'); -- 102     


/*Inserting contributor song pairs*/
INSERT INTO SongContributions
        (songID, contributorID)
        VALUES
        (1, 1),		--Abigail's list starts
        (1, 2),
        (2, 3),
        (2, 4),
        (3, 5),
        (3, 6),
        (4, 3),
        (4, 4),
        (5, 3),
        (5, 4),
        (6, 3),
        (6, 4),
        (7, 3),
        (7, 4),
        (8, 6),
        (8, 7),		--Abigail's list ends
        (9, 8),		-- Anushka's List Starts
        (9, 9),
        (9, 10),
        (10, 11),
        (10, 12),
        (10, 13),
        (10, 14),
        (10, 15),
        (11, 16),
        (11, 17),
        (11, 18),
        (11, 19),
        (11, 20),
        (11, 21),
        (11, 22),
        (11, 23),
        (11, 24),
        (12, 25),
        (12, 26),
        (12, 27),
        (12, 28),
        (12, 29),
        (12, 30),
        (13, 31),
        (13, 32),
        (13, 33),
        (13, 34),
        (14, 35),
        (14, 36),
        (15, 37),
        (15, 38),
        (15, 39),
        (15, 40),
        (15, 41),
        (15, 42),
        (16, 43),
        (16, 44),
        (16, 45),	-- Anushka's List Ends
        (17, 46),       -- Vansh's Starts
        (17, 47),
        (18, 48),
        (18, 49),
        (19, 50),
        (19, 51),
        (20, 52),
        (20, 53),
        (21, 54),
        (21, 55),
        (22, 56),
        (22, 57),
        (23, 58),
        (23, 59),
        (24, 60),
        (24, 61),       -- Vansh's Ends
	(25, 62),
	(25, 63),
	(25, 64),
	(25, 65),
	(25, 66),
	(25, 67),
	(26, 68),
	(26, 69),
	(26, 70),
	(26, 71),
	(27, 72),
	(27, 73),
	(27, 74),
	(27, 75),
	(27, 76),
	(28, 77),
	(28, 78),
	(28, 79),
	(28, 80),
	(28, 81),
	(29, 82),
	(29, 83),
	(29, 84),
	(29, 85),
	(30, 86),
	(30, 87),
	(30, 88),
	(30, 89),
	(30, 90),
	(31, 91),
	(31, 92),
	(31, 93),
	(31, 94),
	(31, 95),
	(31, 96),
	(31, 97),
	(31, 98),
	(32, 99),
	(32, 100),
	(32, 101),
	(32, 102);

/*Inserting sample users*/
INSERT INTO Participants(firstName, lastName)
	VALUES
	('John', 'Smith'),
	('Jane', 'Doe'),
	('Justin', 'Beiber'),
	('Chandler', 'Bing'),
	('Michael', 'Scott'),
	('Jim', 'Halpert'),
	('Pam', 'Beesly'),
	('Andy', 'Bernard'),
	('Dwight', 'Schrute'),
	('Angela', 'Martin');

/*Inserting sample version for songs*/
INSERT INTO KaraokeVersions(songID, version)
	VALUES
	(1, "Duet"), -- 1
	(2, "Solo"), -- 2
	(2, "Duet"), -- 3
	(3, "Solo"), -- 4
	(4, "Solo"), -- 5
	(5, "Solo"), -- 6
	(6, "Solo"), -- 7
	(7, "Solo"), -- 8
	(8, "Duet"), -- 9
	(8, "Solo"), -- 10
	(9, "Solo"), -- 11
	(9, "Duet"), -- 12
	(10,"Duet"), -- 13
	(10,"Solo"), -- 14
	(11,"Solo"), -- 15
	(12,"Solo"), -- 16
	(13,"Duet"), -- 17
	(13,"Solo"), -- 18
	(14,"Solo"), -- 19
	(15,"Solo"), -- 20
	(15,"Duet"), -- 21
	(16,"Solo"), -- 22
	(16,"Duet"), -- 23
	(17,"Duet"), -- 24
	(18,"Solo"), -- 25
	(18,"Duet"), -- 26
	(18,"Solo"), -- 27
	(19,"Solo"), -- 28
	(20,"Solo"), -- 29
	(20,"Duet"), -- 30
	(21,"Solo"), -- 31
	(21,"Duet"), -- 32
	(22,"Solo"), -- 33
	(23,"Duet"), -- 34
	(24,"Solo"), -- 35
	(25,"Solo"), -- 36
	(26,"Duet"), -- 37
	(26,"Solo"), -- 38
	(27,"Solo"), -- 39
	(28,"Duet"), -- 40
	(28,"Solo"), -- 41
	(29,"Solo"), -- 42
	(30,"Solo"), -- 43
	(31,"Duet"), -- 44
	(31,"Solo"), -- 45
	(32,"Solo"); -- 46

/*Inserting users into queues*/
INSERT INTO FreeQueue(time, participantID, fileID)
	VALUES
	(CURRENT_TIME(),1,1),
	(CURRENT_TIME(),2,4),
	(CURRENT_TIME(),6,8),
	(CURRENT_TIME(),5,2),
	(CURRENT_TIME(),4,9);

INSERT INTO PriorityQueue(time, participantID, fileID, paidAmount)
	VALUES
	(CURRENT_TIME(),6,3,100),
	(CURRENT_TIME(),8,2,200),
	(CURRENT_TIME(),2,7,700),
	(CURRENT_TIME(),10,6,100),
	(CURRENT_TIME(),9,4,400);
