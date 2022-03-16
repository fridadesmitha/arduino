<?php
date_default_timezone_set("Asia/Bangkok");
echo date_default_timezone_get();
?>

<?php 
include('connection.php');
$ML = $_GET['ml'];
$KET = $_GET['ket'];

$tanggal = date("Y-m-d");
$jam	 = date("H:i:s");

    $sql = "INSERT into `data` (ml, ket, tanggal, jam) VALUES ('$ML', '$KET', '$tanggal', '$jam')";
    if ($con->query($sql) === TRUE) {
      echo "Record successfully";
    } else {
      echo "Error record: " . $con->error;
  }

?>