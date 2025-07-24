--Tìm các giáo viên (MAGV) mà tham gia tất cả các đề tài
--Group by + having
--đếm số lượng đề tài: S(SoLuong)
--Xet mỗi gvi trong ds gv có tham gia đề tài
--GV1
	--Đếm số lượng đề tài tham gia của gvi ==S.Soluong
--GV2
	--Đếm số lượng đề tài tham gia của gvi
--GV3
	--Đếm số lượng đề tài tham gia của gvi
Select magv, count(distinct madt)
from THAMGIADT R
group by magv
having count(distinct madt) = (select count(madt) from detai)

--Tìm các giáo viên (MAGV) mà tham gia tất cả các đề tài
--S: tham gia tất cả các đề tài Detai(madt)
--R(magv, madt): ThamGiaDT
--KQ(magv)

--với mỗi gvi có tham gia dtai:
-- NOT EXIST (Tìm ds các dtai mà gvi chưa tham gia:)
--		DS madt (S)
--	Except
--		DS madt mà gvi đã tham gia
select distinct magv
from THAMGIADT R
where NOT EXISTS 
(
	Select madt from Detai S
	except
	select madt from THAMGIADT R1 where R1.magv = R.MAGV
)
--Cách 2
--với mỗi gvi có tham gia dtai:
-- NOT EXIST (Tìm ds các dtai mà gvi chưa tham gia:)
--	Xét mỗi madt trong DS madt (S)
-- Sao cho: madt not in 
--		DS madt mà gvi đã tham gia
select distinct magv
from THAMGIADT R
where NOT EXISTS 
(
	Select madt from Detai S
	WHERE S.madt NOT IN (--except
	select madt from THAMGIADT R1 where R1.magv = R.MAGV)
)
--Cách 3:
--với mỗi gvi có tham gia dtai:
-- NOT EXIST (Tìm ds các dtai mà gvi chưa tham gia:)
--	Xét mỗi madt_i trong DS madt (S)
--	Sao cho: NOT EXISTS 
--		DS madt_i mà gvi đã tham gia
select distinct magv
from THAMGIADT R
where NOT EXISTS 
(
	Select madt from Detai S
	WHERE NOT EXISTS(--except
					select madt from THAMGIADT R1 
					where R1.magv = R.MAGV AND R1.madt = S.MADT
	)
)

--Q58.	Cho biết tên giáo viên nào 
--mà tham gia đề tài đủ tất cả các chủ đề.
--R: ThamGiaDT (MaGV,MaCD)
--S: ChuDe (MaCD)
--KQ (MaGV)
--Group by + having
Select gv.magv,gv.hoten, count(distinct macd) as SoLuongCD
from THAMGIADT R join DETAI dt on r.MADT=dt.madt join GIANGVIEN gv on gv.magv=R.MAGV
group by gv.magv, gv.HOTEN
having count(distinct macd) = (select count(*) from CHUDE)

--C2
Select magv
from THAMGIADT R join DETAI dt on R.MADT=dt.madt
Where NOT EXISTS (
	Select macd from CHUDE s
	except
	select macd from THAMGIADT R1 join DETAI dt1 on R1.MADT=dt1.madt
	where R1.magv = R.MAGV
)
