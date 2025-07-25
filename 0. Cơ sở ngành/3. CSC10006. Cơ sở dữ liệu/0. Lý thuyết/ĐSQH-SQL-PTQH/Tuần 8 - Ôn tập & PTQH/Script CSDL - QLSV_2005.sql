create database QLSinhVien
go

USE [QLSinhVien]
GO
/****** Object:  Table [dbo].[KhoaHoc]    Script Date: 02/22/2011 11:45:29 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[KhoaHoc](
	[maKhoahoc] [varchar](10) NOT NULL,
	[namBatDau] [int] NULL,
	[namKetThuc] [int] NULL,
 CONSTRAINT [PK_KhoaHoc] PRIMARY KEY CLUSTERED 
(
	[maKhoahoc] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[KhoaHoc] ([maKhoahoc], [namBatDau], [namKetThuc]) VALUES (N'K2002', 2002, 2006)
INSERT [dbo].[KhoaHoc] ([maKhoahoc], [namBatDau], [namKetThuc]) VALUES (N'K2003', 2003, 2007)
INSERT [dbo].[KhoaHoc] ([maKhoahoc], [namBatDau], [namKetThuc]) VALUES (N'K2004', 2004, 2008)
INSERT [dbo].[KhoaHoc] ([maKhoahoc], [namBatDau], [namKetThuc]) VALUES (N'K2005', 2005, 2009)
INSERT [dbo].[KhoaHoc] ([maKhoahoc], [namBatDau], [namKetThuc]) VALUES (N'K2006', 2006, 2010)
INSERT [dbo].[KhoaHoc] ([maKhoahoc], [namBatDau], [namKetThuc]) VALUES (N'K2007', 2007, 2011)
/****** Object:  Table [dbo].[Khoa]    Script Date: 02/22/2011 11:45:29 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Khoa](
	[maKhoa] [varchar](10) NOT NULL,
	[tenKhoa] [nvarchar](100) NULL,
	[namThanhLap] [int] NULL,
 CONSTRAINT [PK_Khoa] PRIMARY KEY CLUSTERED 
(
	[maKhoa] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[Khoa] ([maKhoa], [tenKhoa], [namThanhLap]) VALUES (N'CNSH', N'Công nghệ sinh học', 1990)
INSERT [dbo].[Khoa] ([maKhoa], [tenKhoa], [namThanhLap]) VALUES (N'CNTT', N'Công nghệ thông tin', 1995)
INSERT [dbo].[Khoa] ([maKhoa], [tenKhoa], [namThanhLap]) VALUES (N'DC', N'Địa chất', 2000)
INSERT [dbo].[Khoa] ([maKhoa], [tenKhoa], [namThanhLap]) VALUES (N'DTVT', N'Điện tử viễn thông', 2003)
INSERT [dbo].[Khoa] ([maKhoa], [tenKhoa], [namThanhLap]) VALUES (N'TT', N'Toán-Tin', 1996)
INSERT [dbo].[Khoa] ([maKhoa], [tenKhoa], [namThanhLap]) VALUES (N'VL', N'Vật lý', 1970)
/****** Object:  Table [dbo].[ChuongTrinh]    Script Date: 02/22/2011 11:45:29 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[ChuongTrinh](
	[maChuongTrinh] [varchar](10) NOT NULL,
	[tenChuongTrinh] [nvarchar](100) NULL,
 CONSTRAINT [PK_ChuongTrinh] PRIMARY KEY CLUSTERED 
(
	[maChuongTrinh] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[ChuongTrinh] ([maChuongTrinh], [tenChuongTrinh]) VALUES (N'CNTN', N'Cử nhân tài năng')
INSERT [dbo].[ChuongTrinh] ([maChuongTrinh], [tenChuongTrinh]) VALUES (N'CQ', N'Chính qui')
INSERT [dbo].[ChuongTrinh] ([maChuongTrinh], [tenChuongTrinh]) VALUES (N'CÐ	', N'Cao đẳng')
/****** Object:  Table [dbo].[MonHoc]    Script Date: 02/22/2011 11:45:29 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[MonHoc](
	[maMonHoc] [varchar](10) NOT NULL,
	[tenMonHoc] [nvarchar](100) NULL,
	[maKhoa] [varchar](10) NULL,
 CONSTRAINT [PK_MonHoc] PRIMARY KEY CLUSTERED 
(
	[maMonHoc] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[MonHoc] ([maMonHoc], [tenMonHoc], [maKhoa]) VALUES (N'THCS01', N'Cấu trúc dữ liệu 1', N'CNTT')
INSERT [dbo].[MonHoc] ([maMonHoc], [tenMonHoc], [maKhoa]) VALUES (N'THCS02', N'Hệ điều hành', N'CNTT')
INSERT [dbo].[MonHoc] ([maMonHoc], [tenMonHoc], [maKhoa]) VALUES (N'THT01', N'Toán Cao cấp A1', N'CNTT')
INSERT [dbo].[MonHoc] ([maMonHoc], [tenMonHoc], [maKhoa]) VALUES (N'THT02', N'Toán rời rạc', N'CNTT')
INSERT [dbo].[MonHoc] ([maMonHoc], [tenMonHoc], [maKhoa]) VALUES (N'VLT01', N'Vật lý Cao cấp A1', N'VL')
/****** Object:  Table [dbo].[Lop]    Script Date: 02/22/2011 11:45:29 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Lop](
	[maLop] [varchar](10) NOT NULL,
	[maKhoaHoc] [varchar](10) NULL,
	[maKhoa] [varchar](10) NULL,
	[maChuongTrinh] [varchar](10) NULL,
	[soThuTu] [int] NULL,
 CONSTRAINT [PK_Lop] PRIMARY KEY CLUSTERED 
(
	[maLop] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[Lop] ([maLop], [maKhoaHoc], [maKhoa], [maChuongTrinh], [soThuTu]) VALUES (N'TH2002/01', N'K2002', N'CNTT', N'CQ', 1)
INSERT [dbo].[Lop] ([maLop], [maKhoaHoc], [maKhoa], [maChuongTrinh], [soThuTu]) VALUES (N'TH2002/02', N'K2002', N'CNTT', N'CQ', 2)
INSERT [dbo].[Lop] ([maLop], [maKhoaHoc], [maKhoa], [maChuongTrinh], [soThuTu]) VALUES (N'VL2003/01', N'K2003', N'VL', N'CQ', 1)
/****** Object:  Table [dbo].[SinhVien]    Script Date: 02/22/2011 11:45:29 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[SinhVien](
	[maSinhVien] [varchar](10) NOT NULL,
	[hoTen] [nvarchar](100) NULL,
	[namSinh] [int] NULL,
	[danToc] [nvarchar](20) NULL,
	[maLop] [varchar](10) NULL,
 CONSTRAINT [PK_SinhVien] PRIMARY KEY CLUSTERED 
(
	[maSinhVien] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[SinhVien] ([maSinhVien], [hoTen], [namSinh], [danToc], [maLop]) VALUES (N'0212001', N'Nguyễn Vĩnh An', 1984, N'Kinh', N'TH2002/01')
INSERT [dbo].[SinhVien] ([maSinhVien], [hoTen], [namSinh], [danToc], [maLop]) VALUES (N'0212002', N'Nguyễn Thanh Bình', 1985, N'Kinh', N'TH2002/01')
INSERT [dbo].[SinhVien] ([maSinhVien], [hoTen], [namSinh], [danToc], [maLop]) VALUES (N'0212003', N'Nguyễn Thanh Cường', 1984, N'Kinh', N'TH2002/02')
INSERT [dbo].[SinhVien] ([maSinhVien], [hoTen], [namSinh], [danToc], [maLop]) VALUES (N'0212004', N'Nguyễn Quốc Duy', 1983, N'Kinh', N'TH2002/02')
INSERT [dbo].[SinhVien] ([maSinhVien], [hoTen], [namSinh], [danToc], [maLop]) VALUES (N'0312001', N'Phan Tuấn Anh', 1985, N'Kinh', N'VL2003/01')
INSERT [dbo].[SinhVien] ([maSinhVien], [hoTen], [namSinh], [danToc], [maLop]) VALUES (N'0312002', N'Huỳnh Thanh Sang', 1984, N'Kinh', N'VL2003/01')
/****** Object:  Table [dbo].[GiangKhoa]    Script Date: 02/22/2011 11:45:29 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[GiangKhoa](
	[maGiangKhoa] [varchar](10) NOT NULL,
	[maChuongTrinh] [varchar](10) NULL,
	[maKhoa] [varchar](10) NULL,
	[maMonHoc] [varchar](10) NULL,
	[namHoc] [int] NULL,
	[hocKy] [int] NULL,
	[soTietLyThuyet] [int] NULL,
	[soTietThucHanh] [int] NULL,
	[soTinChi] [int] NULL,
 CONSTRAINT [PK_GiangKhoa] PRIMARY KEY CLUSTERED 
(
	[maGiangKhoa] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[GiangKhoa] ([maGiangKhoa], [maChuongTrinh], [maKhoa], [maMonHoc], [namHoc], [hocKy], [soTietLyThuyet], [soTietThucHanh], [soTinChi]) VALUES (N'THCS01104', N'CQ', N'CNTT', N'THCS01', 2004, 1, 45, 0, 4)
INSERT [dbo].[GiangKhoa] ([maGiangKhoa], [maChuongTrinh], [maKhoa], [maMonHoc], [namHoc], [hocKy], [soTietLyThuyet], [soTietThucHanh], [soTinChi]) VALUES (N'THT01103', N'CQ', N'CNTT', N'THT01', 2003, 1, 60, 0, 5)
INSERT [dbo].[GiangKhoa] ([maGiangKhoa], [maChuongTrinh], [maKhoa], [maMonHoc], [namHoc], [hocKy], [soTietLyThuyet], [soTietThucHanh], [soTinChi]) VALUES (N'THT01203', N'CQ', N'CNTT', N'THT01', 2003, 2, 60, 0, 5)
INSERT [dbo].[GiangKhoa] ([maGiangKhoa], [maChuongTrinh], [maKhoa], [maMonHoc], [namHoc], [hocKy], [soTietLyThuyet], [soTietThucHanh], [soTinChi]) VALUES (N'THT02103', N'CQ', N'CNTT', N'THT02', 2003, 1, 45, 0, 4)
INSERT [dbo].[GiangKhoa] ([maGiangKhoa], [maChuongTrinh], [maKhoa], [maMonHoc], [namHoc], [hocKy], [soTietLyThuyet], [soTietThucHanh], [soTinChi]) VALUES (N'THT02203', N'CQ', N'CNTT', N'THT02', 2003, 2, 45, 30, 4)
/****** Object:  Table [dbo].[KetQua]    Script Date: 02/22/2011 11:45:29 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[KetQua](
	[maSinhVien] [varchar](10) NOT NULL,
	[maGiangKhoa] [varchar](10) NOT NULL,
	[diem] [float] NULL,
	[lanThi] [int] NULL,
 CONSTRAINT [PK_KetQua] PRIMARY KEY CLUSTERED 
(
	[maSinhVien] ASC,
	[maGiangKhoa] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[KetQua] ([maSinhVien], [maGiangKhoa], [diem], [lanThi]) VALUES (N'0212001', N'THCS01104', 1, 6)
INSERT [dbo].[KetQua] ([maSinhVien], [maGiangKhoa], [diem], [lanThi]) VALUES (N'0212001', N'THT01103', 1, 4)
INSERT [dbo].[KetQua] ([maSinhVien], [maGiangKhoa], [diem], [lanThi]) VALUES (N'0212001', N'THT01203', 2, 7)
INSERT [dbo].[KetQua] ([maSinhVien], [maGiangKhoa], [diem], [lanThi]) VALUES (N'0212001', N'THT02203', 1, 8)
INSERT [dbo].[KetQua] ([maSinhVien], [maGiangKhoa], [diem], [lanThi]) VALUES (N'0212002', N'THCS01104', 1, 4)
INSERT [dbo].[KetQua] ([maSinhVien], [maGiangKhoa], [diem], [lanThi]) VALUES (N'0212002', N'THT01103', 1, 8)
INSERT [dbo].[KetQua] ([maSinhVien], [maGiangKhoa], [diem], [lanThi]) VALUES (N'0212002', N'THT02203', 1, 5)
INSERT [dbo].[KetQua] ([maSinhVien], [maGiangKhoa], [diem], [lanThi]) VALUES (N'0212003', N'THCS01104', 1, 7)
INSERT [dbo].[KetQua] ([maSinhVien], [maGiangKhoa], [diem], [lanThi]) VALUES (N'0212003', N'THT01103', 1, 6)
INSERT [dbo].[KetQua] ([maSinhVien], [maGiangKhoa], [diem], [lanThi]) VALUES (N'0212003', N'THT02103', 1, 4)
INSERT [dbo].[KetQua] ([maSinhVien], [maGiangKhoa], [diem], [lanThi]) VALUES (N'0212003', N'THT02203', 2, 6)
INSERT [dbo].[KetQua] ([maSinhVien], [maGiangKhoa], [diem], [lanThi]) VALUES (N'0212004', N'THT01103', 1, 9)
/****** Object:  ForeignKey [FK_GiangKhoa_ChuongTrinh]    Script Date: 02/22/2011 11:45:29 ******/
ALTER TABLE [dbo].[GiangKhoa]  WITH CHECK ADD  CONSTRAINT [FK_GiangKhoa_ChuongTrinh] FOREIGN KEY([maChuongTrinh])
REFERENCES [dbo].[ChuongTrinh] ([maChuongTrinh])
GO
ALTER TABLE [dbo].[GiangKhoa] CHECK CONSTRAINT [FK_GiangKhoa_ChuongTrinh]
GO
/****** Object:  ForeignKey [FK_GiangKhoa_Khoa]    Script Date: 02/22/2011 11:45:29 ******/
ALTER TABLE [dbo].[GiangKhoa]  WITH CHECK ADD  CONSTRAINT [FK_GiangKhoa_Khoa] FOREIGN KEY([maKhoa])
REFERENCES [dbo].[Khoa] ([maKhoa])
GO
ALTER TABLE [dbo].[GiangKhoa] CHECK CONSTRAINT [FK_GiangKhoa_Khoa]
GO
/****** Object:  ForeignKey [FK_GiangKhoa_MonHoc]    Script Date: 02/22/2011 11:45:29 ******/
ALTER TABLE [dbo].[GiangKhoa]  WITH CHECK ADD  CONSTRAINT [FK_GiangKhoa_MonHoc] FOREIGN KEY([maMonHoc])
REFERENCES [dbo].[MonHoc] ([maMonHoc])
GO
ALTER TABLE [dbo].[GiangKhoa] CHECK CONSTRAINT [FK_GiangKhoa_MonHoc]
GO
/****** Object:  ForeignKey [FK_KetQua_GiangKhoa]    Script Date: 02/22/2011 11:45:29 ******/
ALTER TABLE [dbo].[KetQua]  WITH CHECK ADD  CONSTRAINT [FK_KetQua_GiangKhoa] FOREIGN KEY([maGiangKhoa])
REFERENCES [dbo].[GiangKhoa] ([maGiangKhoa])
GO
ALTER TABLE [dbo].[KetQua] CHECK CONSTRAINT [FK_KetQua_GiangKhoa]
GO
/****** Object:  ForeignKey [FK_KetQua_SinhVien]    Script Date: 02/22/2011 11:45:29 ******/
ALTER TABLE [dbo].[KetQua]  WITH CHECK ADD  CONSTRAINT [FK_KetQua_SinhVien] FOREIGN KEY([maSinhVien])
REFERENCES [dbo].[SinhVien] ([maSinhVien])
GO
ALTER TABLE [dbo].[KetQua] CHECK CONSTRAINT [FK_KetQua_SinhVien]
GO
/****** Object:  ForeignKey [FK_Lop_ChuongTrinh]    Script Date: 02/22/2011 11:45:29 ******/
ALTER TABLE [dbo].[Lop]  WITH CHECK ADD  CONSTRAINT [FK_Lop_ChuongTrinh] FOREIGN KEY([maChuongTrinh])
REFERENCES [dbo].[ChuongTrinh] ([maChuongTrinh])
GO
ALTER TABLE [dbo].[Lop] CHECK CONSTRAINT [FK_Lop_ChuongTrinh]
GO
/****** Object:  ForeignKey [FK_Lop_Khoa]    Script Date: 02/22/2011 11:45:29 ******/
ALTER TABLE [dbo].[Lop]  WITH CHECK ADD  CONSTRAINT [FK_Lop_Khoa] FOREIGN KEY([maKhoa])
REFERENCES [dbo].[Khoa] ([maKhoa])
GO
ALTER TABLE [dbo].[Lop] CHECK CONSTRAINT [FK_Lop_Khoa]
GO
/****** Object:  ForeignKey [FK_Lop_KhoaHoc]    Script Date: 02/22/2011 11:45:29 ******/
ALTER TABLE [dbo].[Lop]  WITH CHECK ADD  CONSTRAINT [FK_Lop_KhoaHoc] FOREIGN KEY([maKhoaHoc])
REFERENCES [dbo].[KhoaHoc] ([maKhoahoc])
GO
ALTER TABLE [dbo].[Lop] CHECK CONSTRAINT [FK_Lop_KhoaHoc]
GO
/****** Object:  ForeignKey [FK_MonHoc_Khoa]    Script Date: 02/22/2011 11:45:29 ******/
ALTER TABLE [dbo].[MonHoc]  WITH CHECK ADD  CONSTRAINT [FK_MonHoc_Khoa] FOREIGN KEY([maKhoa])
REFERENCES [dbo].[Khoa] ([maKhoa])
GO
ALTER TABLE [dbo].[MonHoc] CHECK CONSTRAINT [FK_MonHoc_Khoa]
GO
/****** Object:  ForeignKey [FK_SinhVien_Lop]    Script Date: 02/22/2011 11:45:29 ******/
ALTER TABLE [dbo].[SinhVien]  WITH CHECK ADD  CONSTRAINT [FK_SinhVien_Lop] FOREIGN KEY([maLop])
REFERENCES [dbo].[Lop] ([maLop])
GO
ALTER TABLE [dbo].[SinhVien] CHECK CONSTRAINT [FK_SinhVien_Lop]
GO
