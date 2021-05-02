<!-- Anushka Verma, Aby Shulgan, Vansh Rai, Vlad Oprescu
     Database
     CSCI Final - Group Project
     04/21/2021
-->

<!DOCTYPE html>                     <!--Main Setup Of An HTML-->
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Dj Interface</title>
</head>
<?php
    include("header.php");          // Includes The Top Header For The Basic HTML
?>
<body>
    <div id="Title">                <!--Stylizes The Title-->
        <h2>DJ Interface</h2>       <!--Title Of The Current Page-->
    </div>
    <div id="wrap-container">       <!--Stylizes The Container As Well As Everything Else On The Page-->
    <form action="./freequeue.php">
        <input type="Submit" style = "font-size: 30px;" value="Free Queue"/><br>    <!--Creates Submit Buttons To Access The Free Queue-->
    </form>
    <br><br>
    <form action="./paidqueue.php">
        <input type="Submit" style = "font-size: 30px;" value="Paid Queue"/><br>    <!--Creates Submit Buttons To Access The Paid Queue-->
    </form>
</body>
<?php 
    include("footer.php");  //Adds The Footer To The Page
?>
</html>
