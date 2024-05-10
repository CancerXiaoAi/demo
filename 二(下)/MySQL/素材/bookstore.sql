/*
 Navicat MySQL Data Transfer

 Source Server         : mylink
 Source Server Type    : MySQL
 Source Server Version : 80022
 Source Host           : localhost:3306
 Source Schema         : bookstore

 Target Server Type    : MySQL
 Target Server Version : 80022
 File Encoding         : 65001

 Date: 07/12/2020 12:04:22
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for book
-- ----------------------------
DROP TABLE IF EXISTS `book`;
CREATE TABLE `book`  (
  `图书编号` char(20) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `图书类别` varchar(20) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL DEFAULT '计算机',
  `书名` varchar(40) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `作者` char(10) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `出版社` varchar(20) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `出版时间` date NOT NULL,
  `单价` float(5, 2) NOT NULL,
  `数量` int(0) NULL DEFAULT NULL,
  `折扣` float(3, 2) NULL DEFAULT NULL,
  `封面图片` varchar(40) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NULL DEFAULT NULL,
  PRIMARY KEY (`图书编号`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = gb2312 COLLATE = gb2312_chinese_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of book
-- ----------------------------
INSERT INTO `book` VALUES ('TP.2462', '计算机', '计算机应用基础', '陆大强', '清华大学出版社', '2018-10-19', 45.00, 45, 0.80, NULL);
INSERT INTO `book` VALUES ('TP.2463', '计算机', '计算机网络技术', '林力辉', '清华大学出版社', '2020-10-16', 25.50, 31, 0.80, 'D\\pic\\ll.jpg');
INSERT INTO `book` VALUES ('TP.2525', '计算机', 'PHP高级语言', '王大卫', '中国青年出版社', '2020-06-20', 33.25, 50, 0.80, 'D:\\pic\\js.jpg');
INSERT INTO `book` VALUES ('TP.6625', '计算机', 'JavaScript编程', '谢为民', '中国青年出版社', '2020-08-05', 33.00, 60, 0.80, NULL);
INSERT INTO `book` VALUES ('Ts.3010', '数据库', 'ORACLE', '张小刚', '北京大学出版社', '2019-08-02', 28.00, NULL, NULL, NULL);
INSERT INTO `book` VALUES ('Ts.3035', '数据库', 'MYSQL数据库', '李刚', '北京大学出版社', '2020-12-26', 20.00, 500, 0.80, 'D:\\pic\\jp.jpg');
INSERT INTO `book` VALUES ('Tw.1283', '网页设计', 'DW网站制作', '李华', '人民邮电出版社', '2015-10-01', 27.00, NULL, NULL, NULL);
INSERT INTO `book` VALUES ('Tw.2562', '网页设计', 'ASP网站制作', '胡莉惠', '中国青年出版社', '2020-07-24', 30.50, 50, 0.80, NULL);
INSERT INTO `book` VALUES ('Tw.3020', '网页设计', '网页程序设计', '刘辉', '清华大学出版社', '2019-02-15', 25.00, NULL, NULL, NULL);

-- ----------------------------
-- Table structure for members
-- ----------------------------
DROP TABLE IF EXISTS `members`;
CREATE TABLE `members`  (
  `用户号` char(18) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `姓名` char(10) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `性别` char(2) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `密码` char(6) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `联系电话` varchar(20) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `注册时间` datetime(0) NULL DEFAULT NULL,
  PRIMARY KEY (`用户号`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = gb2312 COLLATE = gb2312_chinese_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of members
-- ----------------------------
INSERT INTO `members` VALUES ('A0012', '赵宏宇', '男', '080100', '13601234123', '2017-03-04 18:23:45');
INSERT INTO `members` VALUES ('A3013', '张凯', '男', '080100', '13611320001', '2018-01-15 09:12:23');
INSERT INTO `members` VALUES ('B0022', '王林', '男', '080100', '12501234123', '2019-01-12 08:12:30');
INSERT INTO `members` VALUES ('B2023', '李小冰', '女', '080100', '13651111081', '2019-01-18 08:57:18');
INSERT INTO `members` VALUES ('C0132', '张莉', '女', '123456', '13822555432', '2019-09-23 00:00:00');
INSERT INTO `members` VALUES ('C0138', '李华', '女', '123456', '13822551234', '2018-08-23 00:00:00');
INSERT INTO `members` VALUES ('D1963', '张三', '男', '222222', '51985523', '2019-01-23 08:15:45');

-- ----------------------------
-- Table structure for sell
-- ----------------------------
DROP TABLE IF EXISTS `sell`;
CREATE TABLE `sell`  (
  `订单号` int(0) NOT NULL AUTO_INCREMENT,
  `用户号` char(18) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `图书编号` char(20) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL,
  `订购册数` int(0) NOT NULL,
  `订购单价` float(5, 2) NOT NULL,
  `订购时间` datetime(0) NOT NULL,
  `是否发货` varchar(10) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NULL DEFAULT NULL,
  `是否收货` varchar(10) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NULL DEFAULT NULL,
  `是否结清` varchar(10) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NULL DEFAULT NULL,
  PRIMARY KEY (`订单号`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 10 CHARACTER SET = gb2312 COLLATE = gb2312_chinese_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of sell
-- ----------------------------
INSERT INTO `sell` VALUES (1, 'C0132', 'TP.2525', 13, 20.00, '2020-11-14 12:13:49', '已发货', NULL, NULL);
INSERT INTO `sell` VALUES (2, 'D1963', 'TP.2463', 3, 31.50, '2020-11-21 12:25:12', '已发货', NULL, NULL);
INSERT INTO `sell` VALUES (3, 'D1963', 'TP.2525', 6, 23.45, '2020-03-26 12:25:23', '已发货', '已收货', NULL);
INSERT INTO `sell` VALUES (4, 'C0138', 'Ts.3035', 10, 23.50, '2020-08-01 12:13:49', '已发货', '已收货', '已结清');
INSERT INTO `sell` VALUES (5, 'C0138', 'TP.2525', 133, 33.50, '2020-08-01 12:13:49', NULL, NULL, NULL);
INSERT INTO `sell` VALUES (6, 'A3013', 'Tw.2562', 4, 89.00, '2020-08-20 00:00:00', NULL, NULL, NULL);
INSERT INTO `sell` VALUES (7, 'C0138', 'TP.2463', 43, 30.00, '2020-11-08 12:13:49', '已发货', NULL, NULL);
INSERT INTO `sell` VALUES (8, 'C0138', 'Ts.3035', 5, 45.50, '2020-11-21 00:00:00', NULL, NULL, NULL);
INSERT INTO `sell` VALUES (9, 'C0132', 'Tw.1283', 6, 23.00, '2020-11-28 18:23:35', '已发货', '已收货', NULL);

SET FOREIGN_KEY_CHECKS = 1;
