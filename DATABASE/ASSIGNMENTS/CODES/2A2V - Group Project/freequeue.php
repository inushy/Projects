<!-- Anushka Verma, Aby Shulgan, Vansh Rai, Vlad Oprescu
     Database
     CSCI Final - Group Project
     04/21/2021
-->

<!DOCTYPE html>             <!--Main Setup Of An HTML-->
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Free Queue</title>           <!--Title Of The Current Page-->

    <!--Stylizes The Table-->
	<style>
        th {
                padding: 10px 20px 10px 20px;
				border: .5px solid white;
				font-size: 20px
            }
        td {
                padding: 10px 20px 10px 5px;
				border: .5px solid white;
				font-size: 20px
        }
	</style>
</head>
<?php   // Sets Rules That Define How Our Program Is Being Generated
    include("header.php");      // Includes The Top Header For The Basic HTML
    try
    {
        include("mydetails.php");   // Include Database Details

        //Connection to database
        $dsn = "mysql:host=courses;dbname=z1911937";
        $pdo = new PDO($dsn, $username, $password);
        $pdo->setAttribute(PDO::ATTR_ERRMODE,PDO::ERRMODE_EXCEPTION);
        //Running Participants Query
        $mysql = "SELECT DISTINCT FreeQueue.Time, Participants.firstName, Participants.lastName, Songs.title, Songs.artist, KaraokeVersions.fileID, KaraokeVersions.version FROM Participants, Songs, KaraokeVersions, FreeQueue WHERE Participants.ID = FreeQueue.participantID AND FreeQueue.fileID = KaraokeVersions.fileID AND KaraokeVersions.songID = Songs.ID ORDER BY Time ASC;";
        $rspre = $pdo->prepare($mysql);
        echo '<div id="Title"><h2>Free Queue</h2></div><br>';
        echo "<div class='container'><table><tr><th><b>Time</th><th><b>First Name</th><th><b>Last Name</th><th><b>Song Name</th><th><b>Artists</th><th><b>Version</th><th><b>Karaoke ID</th></tr></b>";
        $rspre->execute();
        $rows = $rspre->fetchAll(PDO::FETCH_ASSOC);
        foreach($rows as $row)  // Prints The Results
        {
            echo "<tr><td><b>".$row["Time"]."</td><td><b>".$row["firstName"]."</td><td><b>".$row["lastName"]."</td><td><b>".$row["title"]."</td><td><b>".$row["artist"]."</td><td><b>".$row["version"]."</td><td><b>".$row["fileID"]."</td></tr>";
        }
        echo "</table></div>";
    }
    catch(PDOexception $e)  // Otherwise Prints Error Message When Failed To Connect With The Database
    {
        echo "Sorry But The Connection To Database Failed: " . $e->getMessage();
    }
?> <!--Closes The PHP Tag-->
<?php 
    include("footer.php"); //Adds The Footer To The Page
?>
</html>
