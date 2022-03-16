<?php 
include('connection.php');
$NAMA = $_POST['namapasien']; 
$RUANG = $_POST['ruangpasien'];
echo $NAMA;
echo $RUANG;

$result = mysqli_query($con, "UPDATE data2 SET namapasien='$NAMA',ruangpasien='$RUANG' WHERE id=1");
if ($con->query($result) === TRUE) {
    echo "Record updated successfully";
} else {
    header("location: welcome.php");
    echo "Error updating record: " . $con->error;
}
$con->close();

?>

