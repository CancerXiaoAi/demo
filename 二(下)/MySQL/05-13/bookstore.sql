-- MySQL dump 10.13  Distrib 8.0.21, for Win64 (x86_64)
--
-- Host: localhost    Database: book
-- ------------------------------------------------------
-- Server version	8.0.21

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Current Database: `book`
--

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `book` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;

USE `book`;

--
-- Table structure for table `book`
--

DROP TABLE IF EXISTS `book`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `book` (
  `图书编号` char(20) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `图书类别` varchar(20) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL DEFAULT '计算机',
  `书名` varchar(40) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `作者` char(10) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `出版社` varchar(20) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `出版时间` date NOT NULL,
  `单价` float(5,2) NOT NULL,
  `数量` int DEFAULT NULL,
  `折扣` float(3,2) DEFAULT NULL,
  `封面图片` varchar(40) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci DEFAULT NULL,
  PRIMARY KEY (`图书编号`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=gb2312 ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `book`
--

LOCK TABLES `book` WRITE;
/*!40000 ALTER TABLE `book` DISABLE KEYS */;
INSERT INTO `book` VALUES ('TP.2462','计算机','计算机应用基础','陆大强','清华大学出版社','2018-10-19',45.00,45,0.80,NULL),('TP.2463','计算机','计算机网络技术','林力辉','清华大学出版社','2020-10-16',25.50,31,0.80,'D\\pic\\ll.jpg'),('TP.6625','计算机','JavaScript编程','谢为民','中国青年出版社','2020-08-05',33.00,60,0.80,NULL),('Ts.3010','数据库','ORACLE','张小刚','北京大学出版社','2019-08-02',28.00,NULL,NULL,NULL),('Ts.3035','数据库','MYSQL数据库','李刚','北京大学出版社','2020-12-26',20.00,500,0.80,'D:\\pic\\jp.jpg'),('Tw.123','计算机','PHP高级语言','王大卫','中国青年出版社','2020-06-20',33.25,50,0.80,'D:\\pic\\js.jpg'),('Tw.1283','网页设计','DW网站制作','李华','人民邮电出版社','2015-10-01',27.00,NULL,NULL,NULL);
/*!40000 ALTER TABLE `book` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `members`
--

DROP TABLE IF EXISTS `members`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `members` (
  `用户号` char(18) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `姓名` char(10) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `性别` char(2) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `密码` char(6) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `联系电话` varchar(20) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `注册时间` datetime DEFAULT NULL,
  PRIMARY KEY (`用户号`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=gb2312 ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `members`
--

LOCK TABLES `members` WRITE;
/*!40000 ALTER TABLE `members` DISABLE KEYS */;
INSERT INTO `members` VALUES ('A0012','赵宏宇','男','080100','13601234123','2017-03-04 18:23:45'),('A3013','张凯','男','080100','13611320001','2018-01-15 09:12:23'),('B0022','王林','男','080100','12501234123','2019-01-12 08:12:30'),('B2023','李小冰','女','080100','13651111081','2019-01-18 08:57:18'),('C0132','张莉','女','123456','13822555432','2019-09-23 00:00:00'),('C0138','李华','女','123456','13822551234','2018-08-23 00:00:00'),('D1963','张三','男','222222','51985523','2019-01-23 08:15:45');
/*!40000 ALTER TABLE `members` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `sell`
--

DROP TABLE IF EXISTS `sell`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `sell` (
  `订单号` int NOT NULL AUTO_INCREMENT,
  `用户号` char(18) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `图书编号` char(20) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `订购册数` int NOT NULL,
  `订购单价` float(5,2) NOT NULL,
  `订购时间` datetime NOT NULL,
  `是否发货` varchar(10) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci DEFAULT NULL,
  `是否收货` varchar(10) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci DEFAULT NULL,
  `是否结清` varchar(10) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci DEFAULT NULL,
  PRIMARY KEY (`订单号`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=gb2312 ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `sell`
--

LOCK TABLES `sell` WRITE;
/*!40000 ALTER TABLE `sell` DISABLE KEYS */;
INSERT INTO `sell` VALUES (1,'C0132','TP.2525',13,20.00,'2020-11-14 12:13:49','已发货',NULL,NULL),(2,'D1963','TP.2463',3,31.50,'2020-11-21 12:25:12','已发货',NULL,NULL),(3,'D1963','TP.2525',6,23.45,'2020-03-26 12:25:23','已发货','已收货',NULL),(4,'C0138','Ts.3035',10,23.50,'2020-08-01 12:13:49','已发货','已收货','已结清'),(5,'C0138','TP.2525',133,33.50,'2020-08-01 12:13:49',NULL,NULL,NULL),(6,'A3013','Tw.2562',4,89.00,'2020-08-20 00:00:00',NULL,NULL,NULL),(7,'C0138','TP.2463',43,30.00,'2020-11-08 12:13:49','已发货',NULL,NULL),(8,'C0138','Ts.3035',5,45.50,'2020-11-21 00:00:00',NULL,NULL,NULL),(9,'C0132','Tw.1283',6,23.00,'2020-11-28 18:23:35','已发货','已收货',NULL);
/*!40000 ALTER TABLE `sell` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-05-13 14:31:18
