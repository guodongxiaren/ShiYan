USE market
-- 需要保证上层文件夹已经存在
-- 全库备份
EXEC sp_addumpdevice 'disk','databackup','E:\wangwei\sql\market.bak' 
BACKUP DATABASE market TO databackup
-- 差异备份 
EXEC sp_addumpdevice 'disk','diffbackup1','E:\wangwei\sql\market_diff1.bak'
EXEC sp_addumpdevice 'disk','diffbackup2','E:\wangwei\sql\market_diff2.bak'

BACKUP DATABASE market TO diffbackup1 WITH DIFFERENTIAL 
BACKUP DATABASE market TO diffbackup2 WITH DIFFERENTIAL 

-- 日志备份(更改数据库的属性--选项里面的恢复模式为‘大容量日志’) 
EXEC sp_addumpdevice 'disk','logbackup1','E:\wangwei\sql\market_log1.bak'
EXEC sp_addumpdevice 'disk','logbackup2','E:\wangwei\sql\market_log2.bak'

BACKUP LOG market TO logbackup1 WITH NORECOVERY
BACKUP LOG market TO logbackup2 WITH NORECOVERY


-- 恢复全库备份
RESTORE DATABASE market FROM databackup WITH  NORECOVERY 

-- 恢复第二次差异备份 
RESTORE DATABASE market FROM diffbackup2 WITH NORECOVERY 

-- 恢复第一个日志备份 
RESTORE DATABASE market FROM logbackup1 WITH NORECOVERY 

-- 恢复第二个日志备份 
RESTORE DATABASE market FROM logbackup2 WITH NORECOVERY

-- 查看逻辑设备中的逻辑文件名的语法
 RESTORE FILELISTONLY from diffbackup1
 -- 删除逻辑设备的语法
EXEC sp_dropdevice 'databackup'
