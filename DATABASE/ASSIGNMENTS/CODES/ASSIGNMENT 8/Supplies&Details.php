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
                    echo "Your Supplies: ";
                    include("mydetails.php");
                    include("mytables.php");
                    try
                    {
                        $dsn = "mysql:host=courses;dbname=z1911937";
                        $pdo = new PDO($dsn, $username, $password);
                        $pdo->setAttribute(PDO::ATTR_ERRMODE,PDO::ERRMODE_EXCEPTION);
                        $rsSupp =$pdo->query("SELECT * FROM S;");
                        $rows = $rsSupp->fetchAll(PDO::FETCH_ASSOC);
                        drawtable($rows);
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