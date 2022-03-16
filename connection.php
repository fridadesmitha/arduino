<?php 
    $server = "localhost";
    $username = "root";
    $password = "";
    $database = "infus";

    $con = mysqli_connect($server, $username, $password);
    $db = mysqli_select_db($con, $database);
?>