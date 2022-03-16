<?php
include ('connection.php');
  $result = mysqli_query($con, "SELECT * FROM data2 LIMIT 1");
  $outp = mysqli_fetch_assoc($result);
  echo json_encode($outp);
?>
