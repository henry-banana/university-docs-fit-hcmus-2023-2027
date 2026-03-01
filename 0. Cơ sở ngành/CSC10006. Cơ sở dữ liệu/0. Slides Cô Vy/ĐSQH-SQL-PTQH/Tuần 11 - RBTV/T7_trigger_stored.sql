--mỗi gv không tham gia quá 4 đề tài
--				T	X	S
--ThamGiaDT		+	-	+(magv,madt)
--đếm số đề tài đã tham gia của gv này
--nếu đủ 4 thì báo lỗi ko cho phân công
--nếu chưa đủ: thực hiện phân công
insert into THAMGIADT (magv,madt,stt) 
values ('008','004',1)
go
alter proc ThemPhanCong
	@magv varchar(4),
	@madt varchar(4),
	@stt int
as
begin
	--đếm số dtai đã tham gia của @magv
	if(select count(distinct madt) from THAMGIADT 
	where magv = @magv)<=3
	begin
		insert into THAMGIADT (magv, madt,stt)
		values (@magv,@madt,@stt)
		print 'Thêm thành công'
	end
	else
	begin
		raiserror('Đã đủ 4 đề tài',15,1)
		return
	end
end
go
--gọi thực thi thủ tục:
exec ThemPhanCong '008','005',1
--viết thủ tục
--declare @x int = 0
--set @x = 1
--set @x = (select luong from GIANGVIEN where magv='001')
--print @x


--Lương của trưởng bộ môn phải lớn hơn 50000
--bảng tầm hưởng
--			T				X	S
--GiaoVien	-				-	+(Luong,magv)
--BoMon		+(truongbm)		-	+(truongbm)
--C1: kiểm tra bằng trigger
--trigger này được gọi sau khi hành động update trên bảng giảng viên được thực hiện xong
--update GiangVien set luong = newluong where magv='001'
--thực hiện update cập nhật lương mới cho gv 001
--gv001 lương đang là 50000 -> 30000
--sqlserver gọi trigger tg_ktrluongtrbm xem có vi pham ko
--nếu có vi phạm: huỷ hành động cập nhật, đưa dl về trạng thái trước khi cập nhật
GO
create trigger tg_KTLuongTrgBM
ON GiangVien
For update
as
begin
	--cần lấy ds các dòng vừa được cập nhật
	--sử dụng trong bảng: inserted
	if exists (select * 
				from inserted i join BOMON bm 
				on i.magv = bm.TRUONGBM
				where luong<50000)
	begin
		--báo lỗi & huỷ hành động cập nhật
		raiserror('Luong trưởng bm phải lớn hơn 50000',15,1)
		rollback --huỷ hành động cập nhật
		return
	end
end

update GIANGVIEN set luong = 20000 where magv = '002'
select * from GIANGVIEN
--viết thủ tục: 
--thêm 1 gv, biết rằng trưởng bm phải là gv cùng bm

