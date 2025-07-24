--cho ds các gv tham gia tất cả đề tài
--R: gv tham gia đề tài (magv,madt của ThamGiaDT)
--S: tất cả đề tài (MaDT của Detai)
--KQ: ds các gv (magv thuộc R)
--Với mỗi magv trong R, tìm:
select magv
from THAMGIADT R1
where not exists (
--Không tìm thấy (
--	DS madt mà magv này chưa tham gia
--		ds tất cả đề tài
	select madt from detai S
--	trừ
	except
--		ds đề tài mà gv này đã tham gia
	select madt from THAMGIADT R2
	where R2.magv = R1.magv
--)
)
--hoặc
--Với mỗi magv trong R, tìm:
select magv
from THAMGIADT R1
where not exists (
	select madt from detai S
	where not exists 
	(
		select 1 from thamgiadt  
		where R2.Magv = R1.magv and
			R2.madt = S.Madt
	)
--Không tìm thấy (
--	DS madt mà magv này chưa tham gia
--		Với mỗi madt trong đề tài
--		ko tìm thấy(tìm trong ThamGiaDT 1 dòng của magv đang xét
--			và mã đề tài đang xét)
--for each magvi from thamgiadt
--not exists	
--for each madtj from S
--		not exists tìm 1 dòng trong thamgiadt r2 thoả
			--(magvi,madtj)
--)
)
--cho ds các gv tham gia tất cả đề tài thuộc cde X
--R: GV tham gia dtai của cd x
--S: tất cả đề tài của cd x
--KQ: magv trong R thoả s

--Với mỗi GV tham gia dtai của cd x
--Không tìm thấy
--(
	--DS đề tài của cd X mà gv này chưa tham gia
	--	DS tất cả đề tài cd x
	--trừ 
	--	ds đề tài cd x mà gv này đã tham gia
--)