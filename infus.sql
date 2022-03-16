-- phpMyAdmin SQL Dump
-- version 4.8.4
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Waktu pembuatan: 06 Feb 2019 pada 08.23
-- Versi server: 10.1.37-MariaDB
-- Versi PHP: 7.3.0

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `infus`
--

-- --------------------------------------------------------

--
-- Struktur dari tabel `admin`
--

CREATE TABLE `admin` (
  `username` varchar(16) NOT NULL,
  `password` varchar(16) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data untuk tabel `admin`
--

INSERT INTO `admin` (`username`, `password`) VALUES
('ajang', '1234');

-- --------------------------------------------------------

--
-- Struktur dari tabel `data`
--

CREATE TABLE `data` (
  `no` int(255) NOT NULL,
  `ml` text NOT NULL,
  `ket` text NOT NULL,
  `tanggal` text NOT NULL,
  `jam` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data untuk tabel `data`
--

INSERT INTO `data` (`no`, `ml`, `ket`, `tanggal`, `jam`) VALUES
(1, '102', 'Tinggal Setengah', '2019-02-05', '19:03:14'),
(2, '18', 'Kosong', '2019-02-05', '19:03:21'),
(3, '500', 'Masih Penuh', '2019-02-05', '19:03:33'),
(4, '487', 'Masih Penuh', '2019-02-05', '19:03:56'),
(5, '487', 'Masih Penuh', '2019-02-05', '19:04:20'),
(6, '0', 'Kosong', '2019-02-05', '19:16:08'),
(7, '64', 'Tinggal Setengah', '2019-02-05', '19:16:15'),
(8, '1', 'Kosong', '2019-02-05', '19:18:34');

-- --------------------------------------------------------

--
-- Struktur dari tabel `data2`
--

CREATE TABLE `data2` (
  `id` int(255) NOT NULL,
  `namapasien` text NOT NULL,
  `ruangpasien` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data untuk tabel `data2`
--

INSERT INTO `data2` (`id`, `namapasien`, `ruangpasien`) VALUES
(1, 'Frida Desmitha', 'Sakura 16');

--
-- Indexes for dumped tables
--

--
-- Indeks untuk tabel `admin`
--
ALTER TABLE `admin`
  ADD PRIMARY KEY (`username`);

--
-- Indeks untuk tabel `data`
--
ALTER TABLE `data`
  ADD PRIMARY KEY (`no`);

--
-- Indeks untuk tabel `data2`
--
ALTER TABLE `data2`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT untuk tabel yang dibuang
--

--
-- AUTO_INCREMENT untuk tabel `data`
--
ALTER TABLE `data`
  MODIFY `no` int(255) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT untuk tabel `data2`
--
ALTER TABLE `data2`
  MODIFY `id` int(255) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
