<?php
include('connection.php');

$url=$_SERVER['REQUEST_URI'];
header("Refresh: 2; URL=$url");
?>

<html>
 <head>
  <title>INFUS</title>
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" />
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.css">

<style type="text/css">
  body{ font: 14px sans-serif; text-align: center; }
</style>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js"></script>
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/2.2.0/jquery.min.js"></script>
 </head>
 <body>
     <div class="container">
     <?php
     $result2 = mysqli_query($con,'SELECT * FROM data2 WHERE id=1');
     $row2 = mysqli_fetch_array($result2);
   
     ?>
		<div class="row">
			 <h1>SISTEM MONITORING VOLUME INFUS</h1>
             <br>
             <a href="index.php" class="btn btn-danger" role="button">Logout</a>
             <h3>Nama Pasien: <?php echo $row2['namapasien']; ?></h3>
           
             <h3>Ruang Pasien: <?php echo $row2['ruangpasien']; ?><h3>
		</div>

        <a href="update.php" class="btn btn-info" role="button">Update</a>

        <div align="left" class="badan">
            <br>
             
            <br>


    <div class="table">
    <table class="table table-striped">
        <tr>
        <td class="table_titles">No</td>
        <td class="table_titles">Volume (ML)</td>
        <td class="table_titles">Keterangan</td>
        <td class="table_titles">Tanggal</td>
        <td class="table_titles">Jam</td>
        </tr>
<?php

    $result = mysqli_query($con,'SELECT * FROM data ORDER BY no DESC LIMIT 10');
    $oddrow = true;
    while($row = mysqli_fetch_array($result))
    {
    if ($oddrow)
    {
    $css_class=' class="table_cells_odd"';
    }
    else
    {
    $css_class=' class="table_cells_even"';
    }
    $oddrow = !$oddrow;



    echo "<tr>";
    echo "<td '.$css_class.'>" . $row['no'] . "</td>";
    echo "<td '.$css_class.'>" . $row['ml'] . "</td>";
    echo "<td '.$css_class.'>" . $row['ket'] . "</td>";
    echo "<td '.$css_class.'>" . $row['tanggal'] . "</td>";
    echo "<td '.$css_class.'>" . $row['jam'] . "</td>";
    echo "</tr>";
}

?>
</table>
       <div>
       </div>
       <?php mysqli_close($con); ?>
</body>
</html>
