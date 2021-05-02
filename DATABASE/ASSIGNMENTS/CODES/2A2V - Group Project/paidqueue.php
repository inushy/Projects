<!-- Anushka Verma, Aby Shulgan, Vansh Rai, Vlad Oprescu
     Database
     CSCI Final - Group Project
     04/21/2021
-->

<!DOCTYPE html>				<!--Main Setup Of An HTML-->
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Paid Queue</title>			<!--Title Of The Current Page-->
    <!--Stylizes The Table-->
	<style>
		th {
                padding: 10px 20px 10px 20px;
				border: .5px solid white;
				font-size: 22px
            }
        td {
                padding: 10px 20px 10px 5px;
				border: .5px solid white;
				font-size: 22px
        }
	</style>
</head>
<script>
	function redirect(previousColumn, currentColumn, currentOrder) {
		if(previousColumn == currentColumn) currentOrder = (currentOrder == "ASC" ? "DESC" : "ASC");
		else currentOrder = "ASC";
		//redirect
		window.location.href = window.location.pathname + "?column=" + currentColumn + "&order=" + currentOrder;
	}
</script>
<?php		// Sets Rules That Define How Our Program Is Being Generated
	include("header.php");			// Includes The Top Header For The Basic HTML
	include("mydetails.php");		// Includes Database Details

	//Connection to database
        $dsn = "mysql:host=courses;dbname=z1911937";
        $pdo = new PDO($dsn, $username, $password);
        $pdo->setAttribute(PDO::ATTR_ERRMODE,PDO::ERRMODE_EXCEPTION);

	//default column if not set
	if(!isset($_GET['column']))
		$_GET['column'] = 'paidAmount';

	//default order if not set
	if(!isset($_GET['order']))
		$_GET['order'] = 'DESC';
?>		<!--Closes The PHP Tag-->
<div id="Title">				<!--Stylizes The Title-->
	<h2>Paid Queue</h2></div>	<!--Title Of The Current Page-->
<br>
<div class='container'>			 <!--Stylizes The Container On The Page-->
	<table>
		<tr>					<!--The Table Headers Are Clickable And Sortable-->
			<th style='cursor: pointer;' onclick="redirect('<?php echo $_GET['column'];?>','firstName','<?php echo $_GET['order'];?>')"><b>First Name</b></th>
			<th style='cursor: pointer;' onclick="redirect('<?php echo $_GET['column'];?>','lastName','<?php echo $_GET['order'];?>')"><b>Last Name</b></th>
			<th style='cursor: pointer;' onclick="redirect('<?php echo $_GET['column'];?>','title','<?php echo $_GET['order'];?>')"><b>Song Name</b></th>
			<th style='cursor: pointer;' onclick="redirect('<?php echo $_GET['column'];?>','artist','<?php echo $_GET['order'];?>')"><b>Artists</b></th>
			<th style='cursor: pointer;' onclick="redirect('<?php echo $_GET['column'];?>','version','<?php echo $_GET['order'];?>')"><b>Version</b></th>
			<th style='cursor: pointer;' onclick="redirect('<?php echo $_GET['column'];?>','fileID','<?php echo $_GET['order'];?>')"><b>Karaoke ID</b></th>
			<th style='cursor: pointer;' onclick="redirect('<?php echo $_GET['column'];?>','paidAmount','<?php echo $_GET['order'];?>')"><b>Amount Paid</b></th>
		</tr>
		<?php
			$sql = "SELECT DISTINCT Participants.firstName, Participants.lastName, Songs.title, Songs.artist, version, KaraokeVersions.fileID, PriorityQueue.paidAmount FROM Participants, Songs, KaraokeVersions, PriorityQueue WHERE Participants.ID = PriorityQueue.participantID AND PriorityQueue.fileID = KaraokeVersions.fileID AND KaraokeVersions.songID = Songs.ID ORDER BY ".$_GET['column']." ".$_GET['order'];
			$stmt = $pdo->prepare($sql);
			$stmt->execute();
			$rows = $stmt->fetchAll(PDO::FETCH_ASSOC);
			foreach($rows as $row)		// Prints The Results
			{
				echo "<tr>";
				echo "<td><b>".$row["firstName"]."</b></td>";
				echo "<td><b>".$row["lastName"]."</b></td>";
				echo "<td><b>".$row["title"]."</b></td>";
				echo "<td><b>".$row["artist"]."</b></td>";
				echo "<td><b>".$row["version"]."</b></td>";
				echo "<td><b>".$row["fileID"]."</b></td>";
				echo "<td><b>"."$".$row["paidAmount"]."</b></td>";
				echo "</tr>";
			}
			?>
	</table>
</div>
<?php
	include("footer.php"); 	//Adds The Footer To The Page
?>
</html>
