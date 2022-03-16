<!DOCTYPE html>
<html lang="en">
<head>
  <title>Update Nama & Ruang Pasien</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/js/bootstrap.min.js"></script>
</head>
<body>

<div class="container">
  <h2>Update Nama & Ruang Pasien</h2>
  <form action="/infus/prosesupdate.php" method="post">
    <div class="form-group">
      <label for="namapasien">Nama Pasien:</label>
      <input type="text" class="form-control" id="namapasien" placeholder="Nama Pasien" name="namapasien">
    </div>
    <div class="form-group">
      <label for="ruangpasien">Ruang Pasien:</label>
      <input type="text" class="form-control" id="ruangpasien" placeholder="Ruang Pasien" name="ruangpasien">
    </div>
    <button type="submit" class="btn btn-default">Submit</button>
  </form>
</div>

</body>
</html>
