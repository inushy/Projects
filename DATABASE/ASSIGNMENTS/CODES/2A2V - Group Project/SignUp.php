<!-- Anushka Verma, Aby Shulgan, Vansh Rai, Vlad Oprescu
     Database
     CSCI Final - Group Project
     04/21/2021
-->

<?php
	//Includes
	include("header.php");
        include("mydetails.php");
?>
<!DOCTYPE html>
<html lang="en">
		<script>
			function showDonation() {
				document.getElementById("donation").style.display = "block"; //Shows the textbox for donation
				document.getElementById('donation').required = true; //Makes the donation textbox required
			}
			function hideDonation() {
				document.getElementById("donation").style.display = "none"; //Hides the donation textbox
				document.getElementById('donation').required = false; //Makes the donation textbox not required
			}


		</script>

		<div id="Title">
			<h2>Sign Up?</h2>
		</div>

		<?php
			//Connection to database
				$dsn = "mysql:host=courses;dbname=z1911937";
				$pdo = new PDO($dsn, $username, $password);
				$pdo->setAttribute(PDO::ATTR_ERRMODE,PDO::ERRMODE_EXCEPTION);

			if(isset($_POST['selectedSong']))
			{
				//Query to get information on selected songs
				$sql = "Select * from Songs, KaraokeVersions WHERE KaraokeVersions.fileID = ".explode("|", $_POST['selectedSong'])[0]." AND Songs.ID = ".explode("|", $_POST['selectedSong'])[1].";";
				$stmt = $pdo->prepare($sql);
				$stmt->execute();
				$selectedSong = $stmt->fetch();
			}

			if(!isset($selectedSong['title']))
				header("Location: ./SongSearch.php");

		?>

		<form action ="./SignUpConfirmation.php" method="POST">
			<div id="wrap-container">
				<div class="container">
					<label><b>Selected Song: <?php echo (isset($selectedSong['title']) ? $selectedSong['title'].": ".$selectedSong['version'] : "No Song Selected... Restart process"); ?> </b></label>
					<br><br>
					<label for="first"><b>Singer's First Name</b></br></label> <!--Singer's First Name -->
					<input type="text" placeholder="Enter First Name" name="first" required></br> 
					<label for="last"><b>Singer's Last Name</b></br></label>
					<input type="text" placeholder="Enter Last Name" name="last" required></br>
					<label><b>Queue Type:</b></label> <!-- Picking the type of queue -->
					<br>
					<input type="radio" value="free" name="queueType" onclick = "hideDonation();" checked/> <!-- Onclick of free, call the hideDonation function-->
					<label><b>Free</b></label>
					<br>
					<input type="radio" value="priority" name="queueType" onclick="showDonation();"/> <!-- Onclick of priority, call the showDonation function-->
					<label><b>Priority</b></label>
					<input type="number" placeholder="Donation ($)" name="donation" id="donation" style="display:none; font-size:20px;" min="0.01" step="0.01" max="999.99"></br>
					<input type="hidden" value="<?php echo $selectedSong['fileID'];?>" name="fileId">
					<br>
					<input type="Submit" value="Submit"/><br>

				</div>
			</div>
		</form>

		<?php
			include("footer.php");
		?>
</html>
