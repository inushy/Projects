<!-- Anushka Verma <z1911937>
     Database
     Assignment 8 - PHP FORM
     03/01/2021
-->

<?php
function drawtable($rows)
{
	echo "<table border=1 cellspacing=1>";
	echo "<tr>";	
	foreach($rows[0] as $key => $item )
	{
		echo "<th>$key</th>";
	}
	echo "</tr>";
	foreach($rows as $row)
	{
		echo "<tr>";
		foreach($row as $key => $item)
		{
			echo "<td>$item</td>";
		}
		echo "</tr>";
	}
	echo"</table>";
}
?>