# Mô phỏng hệ thống chụp cắt lớp hình nón (CBCT) sử dụng GATE #

## Tóm tắt: 
Hệ thống cắt lớp công nghiệp sử dụng chùm tia hình nón có vai trò rất quan trọng trong việc đánh giá, kiểm tra phục vụ trong các ngành công nghiệp khác nhau. 
Nghiên cứu này sử dụng mã mô phỏng GATE (một bộ công cụ được xây dựng dựa trên Geant4) để mô phỏng một hệ CBCT đơn giản nhằm nghiên cứu ảnh hưởng của hiệu ứng "làm cứng chùm tia".

## Yêu cầu:
+ Nếu sử dụng Linux hãy cài đặt Geant4, ROOT và GATE.
+ Nếu sử dụng Window có thể dùng V-Gate chạy trên máy ảo.

## Hướng dẫn sử dụng:
+ Hãy thay đổi năng lượng chùm tia, loại phantom trước khi chạy
+ Sử dụng lệnh sau để chạy mô phỏng
  ' >> Gate mac/cbct.mac '
  
 ## Mô tả:
 ### Hình học:
 - Khối World: có kích thước 200x200x200 cm3, chứa không khí
 - Tấm FPD:
 - Phantom: có dạng hình trụ gồm 7 bậc, được cấu tạo từ nhôm
  
   <img src="https://github.com/HungBuiTien/CBCT-GATE/blob/main/phantom.png">
   
   Hình 1. Kích thước phantom nhôm
   
   
   <img src="https://github.com/HungBuiTien/CBCT-GATE/blob/main/geometry.png">
   
   Hình 2. Hình ảnh mô phỏng với 50 sự kiện
   
   
 ### Quá trình vật lý:
 - Loại hạt e+, e- và gamma
 - Quá trình vật lý cho e+: Bremsstrahlung, ElectronIonisation
 - Quá trình vật lý cho e-: Bremsstrahlung,  ElectronIonisation
 - Quá trình vật lý cho gamma: Compton, PhotoElectric, RayleighScattering
 
 ### Nguồn phát:
 ### Ghi nhận:
 
 ## Đóng góp:
 
 ## Tác giả:
 **Bùi Tiến Hưng**
 
 Nghiên cứu viên - Viện Năng lượng nguyên tử Việt Nam (VINATOM)
 
 Email: _hungbuitien19081997@gmail.com_
