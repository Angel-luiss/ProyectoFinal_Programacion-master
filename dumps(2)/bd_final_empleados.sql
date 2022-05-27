-- MySQL dump 10.13  Distrib 8.0.28, for Win64 (x86_64)
--
-- Host: localhost    Database: bd_final
-- ------------------------------------------------------
-- Server version	8.0.28

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `empleados`
--

DROP TABLE IF EXISTS `empleados`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `empleados` (
  `idempleado` int NOT NULL AUTO_INCREMENT,
  `nombres` varchar(60) DEFAULT NULL,
  `apellidos` varchar(60) DEFAULT NULL,
  `direccion` varchar(80) DEFAULT NULL,
  `telefono` varchar(25) DEFAULT NULL,
  `dpi` varchar(15) DEFAULT NULL,
  `genero` bit(1) DEFAULT NULL,
  `fecha_nacimiento` date DEFAULT NULL,
  `idpuesto` smallint DEFAULT NULL,
  `fecha_inicio_labores` date DEFAULT NULL,
  `fechaingreso` datetime DEFAULT NULL,
  PRIMARY KEY (`idempleado`),
  KEY `idpuesto_puesto_empleados_idx` (`idpuesto`)
) ENGINE=InnoDB AUTO_INCREMENT=20 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `empleados`
--

LOCK TABLES `empleados` WRITE;
/*!40000 ALTER TABLE `empleados` DISABLE KEYS */;
INSERT INTO `empleados` VALUES (2,'alberto','jimenez','ciudad','555','3055',_binary '','1973-08-01',0,'1973-08-01','1973-08-01 00:00:00'),(3,'fernando','talva','ciudad','555','3948',_binary '','2002-03-01',1,'2021-06-21','2021-06-22 00:00:00'),(4,'fernando','talva','ciudad','555','3948',_binary '','2002-03-01',1,'2021-06-21','2021-06-22 00:00:00'),(6,'willis','perez','ciudad','5555','305568418',_binary '','1996-12-19',1,'2015-01-01','2016-03-01 08:00:00'),(7,'willi','perez','ciudad','4775','3055',_binary '','1996-12-19',2,'1996-12-19','1996-12-19 00:00:00'),(8,'christian','sapon','ciudad','888','3055',_binary '','2002-03-01',1,'2002-03-01','2002-03-01 00:00:00'),(9,'fatima','perez sapon','ciudad','555','3044',_binary '\0','2011-07-11',0,'2015-03-05','2015-03-03 00:00:15'),(10,'cesar agusto','sanchez valle','pastores sacatepequez','4775','3055684180301',_binary '','1973-08-01',3,'1973-08-01','1973-08-01 00:00:01'),(12,'angelica maria','perez mendoza','Santa Cruz del Quiche','5931','3055',_binary '\0','1973-08-01',3,'1973-08-01','1973-08-01 12:30:01'),(13,'alex','valle','ciudad','555','3055',_binary '','2002-03-01',0,'2002-03-01','2002-03-01 00:00:01'),(14,'willi','perez','ciudad','4775','3999',_binary '','2022-05-19',0,'2002-03-19','2002-03-19 00:00:00'),(15,'maria','reyes','ciudad','4885','3055',_binary '\0','2002-03-19',2,'2002-03-19','2002-03-19 00:00:00'),(16,'josue','oliva','ciuda','555','3',_binary '','2002-03-19',1,'2002-03-19','2002-03-19 00:00:00'),(17,'eliza','lopez','ciudad','333','333',_binary '','2002-03-01',2,'2002-03-01','2022-05-25 17:08:59'),(18,'eliza2','lopez2','ciudad','300','333',_binary '\0','2002-03-01',1,'2002-03-01','2022-05-25 17:10:38'),(19,'eliza3','lopez3','ciudad','555','20000',_binary '\0','1998-05-26',3,'1998-05-26','2022-05-26 00:13:03');
/*!40000 ALTER TABLE `empleados` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-05-26 16:19:22
