数据库完整性
=========
数据库的完整性指的是数据的正确性和相容性  
为了维护数据库的完整性，DBMS必须能够：
- 提供定义完整性约束条件的机制
- 提供完整性检查的方法
- 违约处理

[第2章](../第02章 关系数据库/关系的完整性.md)，已经介绍了关系数据库的三类完整性约束：
- 实体完整性
- 参照完整性
- 用户定义的完整性

##实体完整性
###实体完整性的定义
关系模型的实体完整性在CREATE TABLE中用PRIMARY KEY定义。
```sql
	-- 在表级定义主码
	CREATE TABLE mytable(
	    ID INT NOT NULL,
	    username VARCHAR(16) NOT NULL,
	    PRIMARY KEY(ID)
	);
	-- 在列级定义主码
	CREATE TABLE mytable(
	    ID INT PRIMARY KEY,
	    username VARCHAR(16) NOT NULL
	);
```
由上可知，有两种主码定义方法。但是两者不尽相同。**指定多个字段做主码**是无法在列级定义主码的，这种情况下只能在表级定义主码。
>在列级定义主码，主码的属性不需要再指明NOT NULL。而在表级定义主码时，需要主码的各个属性都指定NOT NULL。

###违约处理
1. 检查主码值是否唯一，如果不唯一则拒绝插入或修改
2. 检查主码的各个属性是否为空，只要有一个为空就拒绝插入或修改

##参照完整性
###参照完整性的定义
关系模型的参照完整性在CREATE TABLE中用FOREIGN KEY短语定义哪些列为外码，用REFERENCES短语指明这些外码参照哪些表的主码。
```sql
	CREATE TABLE SC (
		Sno CHAR(10),
		Cno CHAR(4),
		PRIMARY KEY (Sno , Cno),
		FOREIGN KEY (Sno)
		    REFERENCES Student (Sno),
		FOREIGN KEY (Cno)
		    REFERENCES Course (Cno)
	);
```
###违约处理
1. 拒绝执行（NO ACTION）
2. 级联操作（CASCADE）
3. 设置为空值

##用户定义的完整性
###属性上约束条件的定义
定义属性上的约束条件，即属性值限制，包括：
- 列值非空（NOT NULL短语）
- 列值唯一（UNIQUE短语）
- 检查列值是否满足一个布尔表达式（CHECK短语）

####栗子：Student表中的Ssex只允许取男或女
```sql
	CREATE TABLE Student(
		Sno CHAR(9) PRIMARY KEY,
		Sname CHAR(8) NOT NULL,
		Ssex CHAR(2) CHECK(Ssex IN ('男','女'))，
		Sage SMALLINT,
		Sdept CHAR(20)
	);
```
>注意!!!MySQL不支持CHECK约束


