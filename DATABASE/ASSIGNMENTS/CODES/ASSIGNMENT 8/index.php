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
        <title>ANUSHKA VERMA, Z1911937</title>	  
    </head>
    <body>
       <div id="wrap"> 
       <h1>CSCI 466 Assignment 8</h1>
            <section class="form-section last-section">
                <h2>Suppliers & Their Details</h2><!-- Step1 -->
                <form action = "http://students.cs.niu.edu/~z1911937/Supplies&Details.php" method="GET"><br>
		        <input type = "Submit" name = "Submit" value = "Supplies & Details"/>
	            </form><br>
                <p>
                <h2>Parts & Their Details</h2><!-- Step2 -->
                <form action = "http://students.cs.niu.edu/~z1911937/Parts&Details.php" method="GET"><br>
		        <input type = "Submit" name = "Submit" value = "Parts & Details"/>
	            </form><br>
                </p>
                <h2>User Selection</h2>
                <h2>(Pick one then click the Submit button)</h2><!-- Step3 -->
                    <form action="http://students.cs.niu.edu/~z1911937/PartSelection.php" method="GET">
                        <input type ="radio" id = "Nut" name = "part" value = "P1">
                        <label for = "Nut">Nut</label><br>
                        <input type ="radio" id = "Bolt" name = "part" value = "P2">
                        <label for = "Bolt">Bolt</label><br>
                        <input type ="radio" id = "Screw" name = "part" value = "P3">
                        <label for = "Screw">Blue Screw</label><br>
                        <input type ="radio" id ="Screw" name = "part" value = "P4">
                        <label for = "Screw">Red Screw</label><br>
                        <input type ="radio" id ="Cam" name = "part" value = "P5">
                        <label for = "Cam">Cam</label><br> 	
                        <input type ="radio" id ="Cog" name = "part" value = "P6">
                        <label for = "Cog">Cog</label><br><br>
                        <input type = "Submit" name = "Submit" value = "Submit"/>
                    </form><br>
                <p>
                <h2>User Selection</h2>
                <h2>(Pick one then click the Submit button)</h2><!-- Step4 -->
                    <form action="http://students.cs.niu.edu/~z1911937/SupplierSelection.php" method="GET">
                        <input type ="radio" id ="Smith" name = "supplied" value = "S1">
                        <label for = "Smith">Smith</label><br>
                        <input type ="radio" id ="Jones" name = "supplied" value = "S2">
                        <label for = "Jones">Jones</label><br>
                        <input type ="radio" id ="Blake" name = "supplied" value = "S3">
                        <label for = "Blake">Blake</label><br>
                        <input type ="radio" id ="Clark" name = "supplied" value = "S4">
                        <label for = "Clark">Clark</label><br>
                        <input type ="radio" id ="Adams" name = "supplied" value = "S5">
                        <label for = "Adams">Adams</label><br><br>
                        <input type = "Submit" name = "Submit" value ="Submit"/>
                    </form><br>
                </p>
                <h2>User Selection</h2>
                <h2>Pick a supplier and a part you want, then type in the quantity you want</h2><!-- Step5 -->
                <h2>(When done, click the Submit button)</h2>
                    <form action="http://students.cs.niu.edu/~z1911937/SelectPartAndSupplierAndBuy.php" method="GET">
                        <input type ="radio" id ="Smith" name = "supplied" value = "S1">
                        <label for = "Smith">Smith</label><br>
                        <input type ="radio" id ="Jones" name = "supplied" value = "S2">
                        <label for = "Jones">Jones</label><br>
                        <input type ="radio" id ="Blake" name = "supplied" value = "S3">
                        <label for = "Blake">Blake</label><br>
                        <input type ="radio" id ="Clark" name = "supplied" value = "S4">
                        <label for = "Clark">Clark</label><br>
                        <input type ="radio" id ="Adams" name = "supplied" value = "S5">
                        <label for = "Adams">Adams</label><br>
                        <input type ="radio" id = "Nut" name = "part" value = "P1">
                        <label for = "Nut">Nut</label><br>
                        <input type ="radio" id = "Bolt" name = "part" value = "P2">
                        <label for = "Bolt">Bolt</label><br>
                        <input type ="radio" id = "Screw" name = "part" value = "P3">
                        <label for = "Screw">Blue Screw</label><br>
                        <input type ="radio" id ="Screw" name = "part" value = "P4">
                        <label for = "Screw">Red Screw</label><br>
                        <input type ="radio" id ="Cam" name = "part" value = "P5">
                        <label for = "Cam">Cam</label><br> 	
                        <input type ="radio" id ="Cog" name = "part" value = "P6">
                        <label for = "Cog">Cog</label><br><br>
                        <p>Quantity? <input type = "text" name= "QTY"></p>
                        <input type = "Submit" name = "Submit" value ="Submit"/>
                    </form><br>
                <h2>Wanna add a Part? Go ahead and pick one!</h2>
                <h2>(Please Submit when done!)</h2><!-- Step6 -->
                    <form action ="http://students.cs.niu.edu/~z1911937/AddANewPart.php" method ="POST">
                        <p>Name? <input type = "text" name = "Part_Name"></p> <br>
                        <p>Color? <input type ="text" name ="Part_Color"></p><br>
                        <p>Weight? <input type ="text" name ="Part_Weight"></p><br>
                        <input type = "Submit" name = "Submit" value = "Submit"/>
                    </form><br>
                <h2>Wanna add a Supplier? Go ahead and pick one!</h2>
                <h2>(Please Submit when done!)</h2><!-- Step7 -->
                    <form action ="http://students.cs.niu.edu/~z1911937/AddANewSupplier.php" method ="POST">
                        <p>Name? <input type = "text" name = "Supp_Name"></p> <br>
                        <p>Status? <input type ="text" name ="Supp_Status"></p><br>
                        <p>City? <input type ="text" name ="Supp_City"></p><br>
                        <input type = "Submit" name = "Submit" value = "Submit"/>
                    </form><br>
            </section>
        <div id="footer">
            <text>&copy;2021 Anushka Verma</text>
        </div>
        </div>
    </body>
</html>