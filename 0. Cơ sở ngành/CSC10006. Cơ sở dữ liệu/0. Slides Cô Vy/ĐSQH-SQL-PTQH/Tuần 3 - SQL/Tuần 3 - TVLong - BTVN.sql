--Đếm số đề tai theo từng cấp quản lý
select CapQL, count(madt) as SODT
from Detai
group by CapQL

select * from Detai
--Đếm số gv của mỗi bm
select mabm, count(MaGV) as SoGV
from GIANGVIEN
group by mabm
--xuất mabm, tenbm, số gv của bm thuộc khoa cntt
--lấy ds các gv thuộc khoa cntt trước
--gom nhóm theo mabm và đếm
select bm.mabm,bm.TENBM, count(gv.MaGV) as SOGVBM
from GIANGVIEN gv join BOMON bm on gv.mabm = bm.mabm
join khoa k on bm.MAKHOA = k.MAKHOA
where k.TENKHOA = N'Công nghệ thông tin'
group by bm.mabm,bm.TENBM
--????-SAI
select bm.mabm,bm.TENBM, count(gv.MaGV) as SOGVBM
from GIANGVIEN gv join BOMON bm on gv.mabm = bm.mabm
join khoa k on bm.MAKHOA = k.MAKHOA
group by bm.mabm,bm.TENBM
having k.TENKHOA = N'Công nghệ thông tin'
--Đếm số đề tài tham gia của mỗi GV, chỉ xuất các gv
--tham gia hơn 3 đề tài

select magv, count(distinct madt) as SoDTTHamGia
from THAMGIADT
group by magv
having count(distinct madt)>3
--select * from THAMGIADT
--cho ds gv không tham gia dtai
--		Lấy ds tất cả magv
--Trừ
--		DS magv trong thamgiadt
select magv from giangvien
except
select magv from THAMGIADT

--hoặc
select magv from giangvien
where magv NOT IN (select magv from THAMGIADT)

--hoặc
select magv from GIANGVIEN gv
where NOT EXISTS (select tg.magv from THAMGIADT tg
					where tg.magv = gv.magv)
--cho ds gv không là trưởng bm

--cho ds gv là trưởng bm nhưng ko tham gia dtai

--cho ds những gv có tham gia dtai cấp nhà nước
--phân cấp + tương quan 131
select distinct magv, dt.madt, capQL
from THAMGIADT tg join detai dt on tg.madt = dt.madt
where dt.CAPQL = N'Nhà nước'

--hoặc
select magv,hoten from giangvien gv
where exists (select distinct magv, dt.madt, capQL
				from THAMGIADT tg join detai dt on tg.madt = dt.madt
		where dt.CAPQL = N'Nhà nước' and tg.magv = gv.magv) 

--hoặc
select magv,hoten from giangvien gv
where magv IN (select distinct magv
				from THAMGIADT tg join detai dt on tg.madt = dt.madt
		where dt.CAPQL = N'Nhà nước') 

--cho ds (mã, tên, sốgv) của các bộ môn đông giảng viên nhất
--đếm số gv của từng bm (1)
--lấy giá trị số gv nhiều nhất sogvmax
--với mỗi bm trong (1) nếu số gv = sogvmax thì xuất
--> các bm có cùng số lượng gv đều xuất hết
select mabm, count(magv) as SOGV
from GIANGVIEN
group by mabm
having count(magv) = (select top 1 count(magv) as SOGV 
						from giangvien 
						group by mabm
						order by SoGV desc)
--hoặc
select mabm, count(magv) as SOGV
from GIANGVIEN
group by mabm
having count(magv) >=ALL (select count(magv) as SOGV 
						from giangvien 
						group by mabm
						)
--đếm số gv của từng bm (1)
--sort sốgv giảm dần
--lấy top 1

--> chỉ dùng khi yêu cầu lấy đúng 1 cái cao nhất
--cho ds các gv bm hệ thống tt tham gia nhiều đề tài nhất
--đếm số dtai tham gia của mỗi gv bm hệ thống thông tin
--tìm slmax
--lọc sogvdtai = slmax
select tg.magv, count(distinct madt) as SODT
from THAMGIADT tg join giangvien gv on tg.magv = gv.magv
join BOMON bm on gv.mabm = bm.mabm
where TENBM = N'Hệ thống thông tin'
group by tg.magv
having count(distinct madt) >=ALL
(
	select count(distinct madt) as SODT
	from THAMGIADT tg join giangvien gv on tg.magv = gv.magv
	join BOMON bm on gv.mabm = bm.mabm
	where TENBM = N'Hệ thống thông tin'
	group by tg.magv
)
--phép chia
--cho ds các magv tham gia tất cả đề tài
--R: thamgiaDT (MaGV,MaDT)
--S: Detai(madt)
--KQ: MaGV
--với mỗi gv trong R
-- ko tồn tại (tìm ds các đề tài mà gv này chưa tham gia)
--					lấy ds tất cả madt DETAI (S)
--					trừ
--					ds madt mà gv này đã tham gia
--trả về rỗng nếu S rỗng
select distinct magv 
from THAMGIADT R
where NOT EXISTS ( Select madt from detai S
					except
					select madt from THAMGIADT 
					where magv = R.magv)

select distinct magv 
from THAMGIADT R
where NOT EXISTS (
				Select madt from detai S
				where madt NOT IN
				(select madt from THAMGIADT
				where magv = R.magv)
)
select distinct magv 
from THAMGIADT R
where NOT EXISTS (
				Select madt from detai S
				where not exists--madt NOT IN
				(select madt from THAMGIADT tg
			where tg.magv = R.magv and s.madt = tg.madt)
)
--trả về tất cả gv nếu S là rỗng
select magv
from giangvien R
where NOT EXISTS ( Select madt from detai S
					except
					select madt from THAMGIADT 
					where magv = R.magv)
--dùng group by + having
--với mỗi gv trong R (có tham gia dtai)
--đếm số dtai tham gia của mỗi gv
--nếu = số detai của bảng dtai -> tham gia tất cả
select magv, count(distinct madt) as sodttg
from thamgiadt R
group by magv
having count(distinct madt) = 
				(select count(madt) from detai s)

--cho biết detai nào được tất cả gv bm httt tham gia
--c1: dùng except
--c2: not in
--c3: not exists
--c4: group by having
--Về nhà:
--CSDL Quản lý bán hàng siêu thi:
-- Cho ds các sản phẩm được tất cả khách hàng TPHCM mua
-- Cho ds các khách hàng chưa mua sản phẩm bột giặt loại A nào
-- Cho ds các sản phẩm chưa bán được trong 3 tháng trở lại đây
-- CHo ds khách hàng mua nhiều lượt nhất trong năm nay
-- Cho ds các khách hàng có tổng tiền mua hàng nhiều nhất
-- cho ds các sản phẩm được mua nhiều nhất
--cho ds các sản phẩm có doanh thu thấp nhất
--CSDL quản lý đề tài:
-- Đếm số đề tài chủ nhiệm của mỗi bộ môn. Xuất mã, tên, số dtai của mỗi bm. Sắp xếp số đề tài giảm dần
-- Đếm số đề tài chủ nhiệm của mỗi giảng viên
-- CHo biết magv, hoten giảng viên chủ nhiệm nhiều đề tài nhất
-- Cho biết giảng viên nào chủ nhiệm hơn 3 đề tài cấp DHQG
-- CHo biết giảng viên nữ nào của bm hệ thống ttin chưa chủ nhiệm đề tài
--