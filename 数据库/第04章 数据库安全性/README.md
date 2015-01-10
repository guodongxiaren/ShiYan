数据库安全性
============
##计算机安全性
计算机系统的三类安全性问题
- 技术安全
- 管理安全
- 政策法律

##数据库安全性控制
###用户标识与鉴别
这是系统提供的最外层安全保护措施。  

常用方法有：
- 用户标识（User Identification）
- 口令（Password）

###存取控制
存取控制机制主要包括两部分：
- 定义用户权限，并将用户权限登记到数据字典中
- 合法权限检查

###自主存取控制（DAC）方法
主要通过SQL语句的GRANT语句和REVOKE语句实现。

###GRANT
该语句可以由DBA或数据所有者发出。  
GRANT语句的一般格式为：
```sql
	GRANT <权限> [,<权限> ]...
	ON <对象类型> <对象名> [,<对象类型> <对象名>]...
	TO <用户> [,<用户> ]...
	[WITH GRANT OPTION];
```
权限字段包括SELECT、INSERT、UPDATE等。ALL PRIVILEGES表示所有权限。   
对象类型比如TABLE，则对象名为表名。  
用户字段，如果是PUBLIC表示全部用户。  
>选项WITH GRANT OPTION如果存在，则表明获得了该权限的用户可以授予该权限给其他用户。

举例：
```sql
	GRANT UPDATE(Sno),SELECT
	ON TABLE Student，Sc
	TO U4
	WITH GRANT OPTION;
```
###REVOKE
回收权限。由DBA或其他授权者发出。  
REVOKE语句的一般格式为：
```sql
GRANT <权限> [,<权限> ]...
	ON <对象类型> <对象名> [,<对象类型> <对象名>]...
	FROM <用户> [,<用户> ]...[CASCADE|RESTRICT];
```
CASCADE表示级联。比如用户U1把UPDATE权限授予了U2，如果指定了选项CASCADE，则收回U1的UPDATE权限之后，U2的UPDATE权限也收回。