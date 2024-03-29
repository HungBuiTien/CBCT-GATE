# Mô phỏng hệ thống chụp cắt lớp hình nón (CBCT) sử dụng GATE #

## Tóm tắt: 
Hệ thống cắt lớp công nghiệp sử dụng chùm tia hình nón có vai trò rất quan trọng trong việc đánh giá, kiểm tra phục vụ trong các ngành công nghiệp khác nhau. 
Nghiên cứu này sử dụng mã mô phỏng GATE (một bộ công cụ được xây dựng dựa trên Geant4) để mô phỏng một hệ CBCT đơn giản nhằm nghiên cứu ảnh hưởng của hiệu ứng "làm cứng chùm tia".

## Yêu cầu:
+ Nếu sử dụng Linux hãy cài đặt Geant4, ROOT và GATE.
+ Nếu sử dụng Window có thể dùng V-Gate chạy trên máy ảo.

## Hướng dẫn sử dụng:
1. Hướng dẫn thay đổi thông số mô phỏng
- Thay đổi vị trí của phantom bằng cách thay đổi giá trị 841.25 mm trong tệp *cbct-geo-phantom-cylinder.mac*:
```c++
/gate/cylSam/placement/setTranslation           841.25 0 0 mm
```

- Thay đổi độ phân giải của tấm FPD bằng cách đổi giá trị (1472 1176) trong tệp *cbct-actor.mac*:
```c++
/gate/actor/DetectorActor/setResolution     1 1472 1176
```



2. Hướng dẫn chạy mô phỏng
- Để chạy tính toán đơn nhân sử dụng lệnh sau:
```Linux Kernel Module
$ Gate mac/cbct.mac
```

- Tính toán song song:

Hãy cài HTCondor trên Linux trước bằng các lệnh sau:
```Linux Kernel Module
$ sudo apt-get install htcondor
$ sudo condor_master
```

Kiểm tra xem HTCondor đã cài thành công hay chưa bằng một trong hai lệnh dưới đây:
```Linux Kernel Module
$ condor_q
$ condor_statuts
``` 

Thay đổi sang chế độ mô phỏng song song bằng dòng:

```c++
/gate/application/startDAQCluster
```

Dùng lệnh sau để phân chia chương trình:
```Linux Kernel Module
$ .../Gate/cluster_tools/jobsplitter/gjs -numberofsplits n -clusterplatform condor -condorscript .../Gate/cluster_tools/jobsplitter/script/condor.script file_name.mac
``` 

Để submit tệp vào trình quản lý HTCondor sử dụng lệnh sau:
```Linux Kernel Module
$ condor_submit file_name.submit
``` 
Kiểm tra tiến trình bằng lệnh:
```Linux Kernel Module
$ condor_q
``` 
- Trường hợp HTCondor bị lỗi không hoạt động, người sử dụng sẽ phải sao chép tất cả các tệp main sau khi được phân tách sang thư mục cùng với tệp main lúc đầu.
Sử dụng lệnh screen và chạy lệnh giống như đối với trường hợp chạy đơn nhân cho từng tệp đầu vào được phân chia. Cách làm này tuy sẽ mất thời gian và công sức nhưng sẽ giúp người sử dụng tránh được nhiều vấn đề khi sử dụng với HTCondor.

3. Hướng dẫn vẽ kết quả
+ Hãy thay đổi năng lượng chùm tia, loại phantom trước khi chạy
+ Sử dụng lệnh sau để chạy mô phỏng


  
 + Sử dụng mã Python để hiển thị kết quả
 <img src="https://github.com/HungBuiTien/CBCT-GATE/blob/main/results.png" width="700" alt="...">
 
  Hình 1. Kết quả mô phỏng với 1E8 sự kiện
  
 ## Mô tả:
 ### Hình học:
 - Khối World: có kích thước 200x200x200 cm3, chứa không khí
 - Tấm FPD:
 - Phantom: có dạng hình trụ gồm 7 bậc, được cấu tạo từ nhôm
  
   <img src="https://github.com/HungBuiTien/CBCT-GATE/blob/main/phantom.png" width="700">
   
   Hình 2. Kích thước phantom nhôm
   
   
   <img src="https://github.com/HungBuiTien/CBCT-GATE/blob/main/geometry.png" width="700">
   
   Hình 3. Hình ảnh mô phỏng với 50 sự kiện
   
   
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
