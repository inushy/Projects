<!-- Anushka Verma, Aby Shulgan, Vansh Rai, Vlad Oprescu
     Database
     CSCI Final - Group Project
     04/21/2021
-->

<!DOCTYPE html>
<html lang="en">

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
<!-- Use jquery library -->
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
<script>
$(document).ready(function()
{
	$('th').click(function()
	{
		var table = $(this).parents('table').eq(0);
		var rows = table.find('tr:gt(0)').toArray().sort(comparer($(this).index()));
		this.asc = !this.asc;
		if(!this.asc)
		{
			rows = rows.reverse();
		}
		for(var i = 0; i < rows.length; i++)
		{
			table.append(rows[i]);
		}
	});

	//Sort song search table
	function comparer(index)
	{
		return function(a, b)
		{
	        	var valA = getCellValue(a, index), valB = getCellValue(b, index);
	        	return $.isNumeric(valA) && $.isNumeric(valB) ? valA - valB : valA.toString().localeCompare(valB);
		}
	}

	//Gets table values
	function getCellValue(row, index)
	{
		return $(row).children('td').eq(index).text();
	}
});

</script>


<?php
	//Includes
	include("header.php");	// Includes The Top Header For The Basic HTML
	include("mydetails.php");	// Includes Database Details

	if(!isset($_POST['searchType']))
	{
		$_POST['searchType'] = 'title';
	}
?>

<div id="Title">					<!--Stylizes The Title-->
	<h2>Song Search?</h2>			<!--Title Of The Current Page-->
</div>

<form action ="./SongSearch.php" method="POST">
	<div id="wrap-container"> 		<!--Stylizes The Container As Well As Everything Else On The Page-->
		<div class="container">		<!--Stylizes The Search Field-->

		<label><b>Search Type:</b></label><br>
		<!--Creates Radio Buttons As Well As Accesses The Search Type For Each Input Area-->
		<input type="radio" value="title" name="searchType" <?php if (isset($_POST['searchType']) && $_POST['searchType'] == "title") echo "checked";?>/>
		<label><b>Song Title</b></label>
		<br>
		<input type="radio" value="artist" name="searchType" <?php if (isset($_POST['searchType']) && $_POST['searchType'] == "artist") echo "checked";?>/>
		<label><b>Artist</b></label>
		<br>
		<input type="radio" value="contributor" name="searchType" <?php if (isset($_POST['searchType']) && $_POST['searchType'] == "contributor") echo "checked";?>/>
		<label><b>Contributor</b></label><br><br>
		<!--Creates Text Box As Well As Accesses The Search Box For Search Input Area-->
		<input type="text" placeholder="Search..." name="searchBox" value="<?php echo (isset($_POST['searchBox']) ? $_POST['searchBox'] : ''); ?>" required></br>
		<input type="Submit" value="Search"/><br>
		</div>
	</div>
</form>

<?php	// Sets Rules That Define How Our Program Is Being Generated
	if(isset($_POST['searchType']) && isset($_POST['searchBox']))
	{
		echo "<div class='container'>";	 //Stylizes The Search Field
		try
		{
			//Connection to database
			$dsn = "mysql:host=courses;dbname=z1911937";
            $pdo = new PDO($dsn, $username, $password);
            $pdo->setAttribute(PDO::ATTR_ERRMODE,PDO::ERRMODE_EXCEPTION);
        }

        catch(PDOexception $e)	// Prints Error Message When Failed To Connect With The Database
        {
            echo "Sorry But The Connection To Database Failed: " . $e->getMessage();
        }

		//If search by title is selected
		if($_POST['searchType'] == 'title')
        {
            $mysql = "select distinct fileID, Songs.ID, Songs.title, Songs.artist, version FROM Songs, SongContributions, Contributors, KaraokeVersions WHERE Songs.ID = SongContributions.songID AND Contributors.ID = SongContributions.contributorID AND KaraokeVersions.songID = Songs.ID AND Songs.Title = ?;";
        }

		//If search by contributor is selected
        if($_POST['searchType'] == 'contributor')
		{
            $mysql = "select distinct fileID, Songs.ID, Songs.title, Songs.artist, version FROM Songs, SongContributions, Contributors, KaraokeVersions WHERE Songs.ID = SongContributions.songID AND Contributors.ID = SongContributions.contributorID AND KaraokeVersions.SongID = Songs.ID AND Contributors.name = ?;";
        }

		//If search by artist is selected
        if($_POST['searchType'] == 'artist')
		{
            $mysql = "select distinct fileID, Songs.ID, Songs.title, Songs.artist, version FROM Songs, SongContributions, Contributors, KaraokeVersions WHERE Songs.ID = SongContributions.songID AND Contributors.ID = SongContributions.contributorID AND KaraokeVersions.SongID = Songs.ID AND Songs.artist = ?";
        }

		//Running song search query
        $stmt = $pdo->prepare($mysql);
        $stmt->execute(array($_POST['searchBox']));
        $rows = $stmt->fetchAll(PDO::FETCH_ASSOC);

        echo "<form action='./SignUp.php' method='POST'>";
		if($rows == false) // Prints Error Message If User Input Doesn't Match Data In The Database
		{
			echo "<b>Sorry, But It Does Not Exist In The Database. Please Try Again!</b><br>";
		}
		else	// Otherwise Prints The Results
		{
			echo "<div class='container'>";
        			echo "<table style='border: 2px solid white;font-size: 25px; '>";
                			echo "<tr>";
						echo "<th></th>";		// Headers Are Clickable And Sortable
                	        		echo "<th style='cursor: pointer;'><b>Song Name</b></th>";
                	        		echo "<th style='cursor: pointer;'><b>Artist</b></th>";
                	        		echo "<th style='cursor: pointer;'><b>Version</b></th>";
                			echo "</tr>";
				foreach($rows as $row)
				{
					echo "<tr>";
					echo "<td><input type='radio' name='selectedSong' value='".$row['fileID']."|".$row['ID']."' required</td>";
					echo "<td><b>".$row["title"]."</b></td>";
	                                echo "<td><b>".$row["artist"]."</b></td>";
	                                echo "<td><b>".$row["version"]."</b></td>";
					echo "</tr>";
				}
				echo "</table>";
			echo "</div>";
			echo "<input type='Submit' value='Select'/>"; 	// Allows User To Submit
		}
        echo "</div>"; // Closes The Container's Div
	}

include('footer.php'); //Adds The Footer To The Page
?>	<!--Closes The PHP Tag-->
</html>
