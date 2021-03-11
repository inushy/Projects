<!-- Anushka Verma <z1911937>
     Database
     Assignment 8 - PHP FORM
     03/01/2021
-->

<!DOCTYPE html>
<html lang="en">
    <head>
        <link href="https://fonts.googleapis.com/css?family=Roboto+Condensed" rel="stylesheet">
	    <link href="https://fonts.googleapis.com/css?family=Quicksand" rel="stylesheet">
        <link rel="stylesheet" href="partsandsupply.css">
        <meta charset="utf-8">
        <title>Assignment-08</title>	  
    </head>
    <body>        
        <div id="wrap"> 
            <div class="column" id="main-container">
                <h1>Parts/Suppliers</h1>
                <h2>Suppliers & Their Details</h2> 
                <?php
                    try
                    {
                        include("mydetails.php");
                        include("mytables.php");
                        $dsn = "mysql:host=courses;dbname=z1911937";
                        $pdo = new PDO($dsn, $username, $password);
                        $pdo->setAttribute(PDO::ATTR_ERRMODE,PDO::ERRMODE_EXCEPTION);
                        $mysql = "INSERT INTO S(SNAME,STATUS,CITY) VALUE(?,?,?)";
                        $rspre = $pdo->prepare($mysql);
                        $rspre->execute(array($_POST["Supp_Name"],$_POST["Supp_Status"],$_POST["Supp_City"]));
                        echo "Supplier Succesfully Added!";
                    }
                    catch(PDOexception $e)
                    {
                        echo "Sorry But The Connection To Database Failed: " . $e->getMessage();
                    }
                ?>
            </div>
        </div>
    </body>
</html> 