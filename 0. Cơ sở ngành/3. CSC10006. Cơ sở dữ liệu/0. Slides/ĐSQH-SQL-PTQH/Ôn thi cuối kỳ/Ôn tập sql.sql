--CHo biết hoten giảng viên, soluong detai qua han,
--tổng kinh phí các đề tài mà gv tham gia theo từng năm
--Đề tài quá hạn?
--kết thúc trước ngày hôm nay & có cv chưa làm được
--lấy ds đề tài quá hạn của mỗi gv theo từng năm & tổng kinh phí theo từng năm
Select T1.magv,T1.Nam, SODTQH, TongKP
from (
Select distinct magv, year(NgayBD) as Nam, count(dt.madt) as SoDTQH
from Detai dt join THAMGIADT tg on dt.madt = tg.MADT
where NGAYKT < getdate() and tg.KETQUA is NULL
group by magv, year(NgayBD)
) as T1
full outer join
(
select distinct magv, year(dt.ngaybd) as Nam,sum( kinhphi) as TongKP
from detai dt join THAMGIADT t on dt.madt = t.madt
group by magv, year(dt.ngaybd)
) as T2 on T1.MAGV = T2.MAGV and T1.Nam = T2.Nam
--
SELECT GV.HOTEN,
(SELECT COUNT(DISTINCT TG.MADT)
FROM THAMGIADT TG JOIN DETAI DT ON
DT.MADT = TG.MADT
WHERE TG.MAGV = GV.MAGV AND
DT.NGAYKT < GETDATE() AND
TG.KETQUA IS NULL) SODTQUAHAN,
SUM(KINHPHI) TONGKINHPHI, nam
FROM GIANGVIEN GV  JOIN (SELECT DISTINCT TG.MADT,KINHPHI, MAGV,YEAR(DT.NGAYBD) NAM
						FROM THAMGIADT TG JOIN DETAI DT
						ON DT.MADT = TG.MADT) TG
ON TG.MAGV = GV.MAGV 
GROUP BY GV.MAGV, GV.HOTEN, NAM

--9.Viết store phân công 1 giáo viên chủ nhiệm 
--1 đề tài cụ thể với điều kiện: 
--Tại thời điểm phân công, giáo viên chỉ được chủ nhiệm tối đa 3 đề tài 
--(kể cả đề tài chưa kết thúc).
go
create proc PhanCongGVCNDT
	@madt varchar(5),
	@magvcn varchar(5)
as
begin
	if not exists (select 1 from detai where madt = @madt)
	begin
		raiserror('madt ko tồn tại', 15,1)
		return
	end
	--đếm số đề tài chưa kết thúc của gv này
	if(select count(madt) from detai where GVCNDT = @magvcn
	and NGAYKT is NULL)<3
		update detai set GVCNDT = @magvcn where madt = @madt
	else
	begin
		raiserror('gv đã chủ nhiệm đủ 3 dtai', 15,1)
		return
	end
end
--goi thực thi
go
exec PhanCongGVCNDT 'gv01','dt01'