<!-- Anushka Verma, Aby Shulgan, Vansh Rai, Vlad Oprescu
     Database
     CSCI Final - Group Project
     04/21/2021
-->

<?php
//Includes
include ('header.php');
include ('mydetails.php');
?>

<!DOCTYPE html>
<html lang="en">

<?php
	//Connection to database
        $dsn = "mysql:host=courses;dbname=z1911937";
        $pdo = new PDO($dsn, $username, $password);
        $pdo->setAttribute(PDO::ATTR_ERRMODE,PDO::ERRMODE_EXCEPTION);

        if(isset($_POST['first']) && isset($_POST['last']))
        {
                try
                {
                        //query to insert participant
                        $mysql = "INSERT INTO Participants(firstName,lastName) VALUES(?,?)";
                        $rspre = $pdo->prepare($mysql);
                        $rspre->execute(array($_POST["first"],$_POST["last"]));
                }
                catch(PDOexception $e)
                {
                        echo "Sorry But The Connection To Database Failed: " . $e->getMessage();
                }
        }

	//Query to get lastest participant added
	$sql = "SELECT max(id) FROM Participants;";
	$stmt = $pdo->prepare($sql);
	$stmt->execute();
	$participant = $stmt->fetch();

	//Insert participant into free queue
	if(isset($_POST['queueType']) && $_POST['queueType'] == "free")
	{
		$mysql = "INSERT INTO FreeQueue(time, participantID, fileID) VALUES(CURRENT_TIME(), ".$participant["max(id)"].", ".$_POST['fileId'].");";
		$stmt = $pdo->prepare($mysql);
		$stmt->execute();
	} //Insert participant into priority queue
	else if(isset($_POST['queueType']) && $_POST['queueType'] == "priority" && isset($_POST['donation']))
	{
		$mysql = "INSERT INTO PriorityQueue(time, participantID, fileID, paidAmount) VALUES(CURRENT_TIME(), ".($participant["max(id)"]).", ".$_POST['fileId'].", ".$_POST['donation'].");";
		$stmt = $pdo->prepare($mysql);
		$stmt->execute();
	}

	if($mysql)
	{
?>

	<div class="container">
		<h2>Sign Up Successful!</h2>
        </div>

<?php
	}
	else
	{
?>

        <div class="container">
                <h2>Sign Up Failed</h2>
        </div>

<?php
	}

include ('footer.php');
?>

</html>
