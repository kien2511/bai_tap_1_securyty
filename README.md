# bai_tap_1_an toan va bao mat thong tin
# BÀI TẬP 1:
TÌM HIỂU CÁC PHƯƠNG PHÁP MÃ HOÁ CỔ ĐIỂN

Caesar

Affine

Hoán vị

Vigenère

Playfair

# Với mỗi phương pháp, hãy tìm hiểu:

Tên gọi

Thuật toán mã hoá, thuật toán giải mã

Không gian khóa

Cách phá mã (mà không cần khoá)

Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
# bài làm

# Caesar cipher
Tên gọi

Caesar cipher (mã Caesar) — một dạng dịch chuyển ký tự theo một số vị trí cố định (đặt theo Julius Caesar).

# Thuật toán

# Mã hoá: với khoá k (0..25) và ký tự p (plaintext, A..Z):

c = (p + k) mod 26

# Giải mã:

p = (c - k + 26) mod 26

(Một phiên bản thường bỏ qua chữ hoa/thường hoặc giữ nguyên định dạng; ở đây ta xử lý chữ in hoa A..Z.)

# Không gian khóa

26 khả năng (0..25).

# Cách phá mã (không cần khóa)

Tấn công brute force: thử 26 giá trị — nhanh.

Phân tích tần suất: nếu văn bản dài, tần suất ký tự cho biết dịch chuyển (so sánh với tần suất tiếng Anh).

Nếu biết mẩu plaintext/ciphertext tương ứng (known-plaintext) có thể xác định k đơn giản

# kết quả 
<img width="1919" height="853" alt="image" src="https://github.com/user-attachments/assets/003ef291-f680-4696-8478-6d8a7487e60f" />


# Affine cipher
Tên gọi

Affine cipher — một biến thể tuyến tính của Caesar: E(x) = (a*x + b) mod 26.

# Thuật toán

Ký tự A..Z tương ứng x = 0..25.

Khoá: (a, b) với gcd(a,26) = 1 (a phải nguyên tố cùng nhau với 26), b từ 0..25.

Mã hoá: E(x) = (a*x + b) mod 26

Giải mã: cần a_inv (nghịch đảo modulo 26): D(y) = a_inv * (y - b) mod 26.

Không gian khóa

Số a có thể là các giá trị nguyên nguyên tố cùng nhau với 26: {1,3,5,7,9,11,15,17,19,21,23,25} (12 giá trị) và b 26 giá trị → tổng 12 * 26 = 312 khoá.

Cách phá mã (không cần khóa)

Brute force: thử 312 cặp (a,b) — thực tế nhanh.

Phân tích tần suất / known-plaintext: nếu có đoạn biết trước, giải được a,b.

Chỉ cần 2 cặp plaintext-ciphertext để giải hệ phương trình tuyến tính modulo 26

# kết quả 
<img width="1919" height="881" alt="image" src="https://github.com/user-attachments/assets/309b40d9-9276-4caf-b67c-87389d577f0c" />


# Hoán vị (Permutation / Transposition cipher)

"Hoán vị" có nhiều biến thể. Ở đây mình trình bày Columnar Transposition (hoán vị cột) — dễ hiểu và phổ biến.

# Tên gọi

Columnar transposition (Hoán vị cột).

# Thuật toán

Chọn một khoá key là chuỗi chữ (ví dụ: "ZEBRA"). Sắp xếp các ký tự khoá theo thứ tự chữ cái để xác định thứ tự cột.

Ghi plaintext theo hàng vào bảng có số cột = độ dài khoá.

Đọc cipher bằng cách đọc các cột theo thứ tự đã sắp xếp.

Ví dụ rút gọn:

key = "ZEBRA" → thứ tự chỉ số: Z(5), E(2), B(1), R(4), A(0) — (thứ tự tăng dần chữ cái => vị trí đọc)

plaintext viết hàng, bù ký tự đặc biệt nếu cần.

Không gian khóa

Tất cả hoán vị của n ký tự: n!. Ví dụ khoá dài 6 → 720 khoá.

Cách phá mã (không cần khóa)

Brute force trên hoán vị (n!) — nếu n nhỏ có thể.

Phân tích cấu trúc: dùng đoán chiều dài cột, tấn công bằng xác suất hoặc dùng n-gram scoring (language model) để chọn hoán vị đúng.

Known-plaintext: có thể trực tiếp phục hồi thứ tự cột.

# kết quả 

<img width="1919" height="691" alt="image" src="https://github.com/user-attachments/assets/fb4a75d1-4648-490f-881a-5f4bf27633f8" />


# Vigenère cipher
Tên gọi

Vigenère cipher — polyalphabetic substitution cipher (mã hoá polyalphabetic), dùng chuỗi khoá lặp lại.

# Thuật toán

Chuyển mỗi ký tự p_i thành số 0..25.

Với khoá k (chuỗi ký tự), k_i lặp lại: c_i = (p_i + k_i) mod 26.

Giải mã: p_i = (c_i - k_i + 26) mod 26.

Không gian khóa

Tùy độ dài khoá m: 26^m (rất lớn nếu m lớn). Nhưng nếu khoá rút ra từ từ vựng có thể nhỏ hơn.

Cách phá mã (không cần khoá)

Kasiski examination: tìm khoảng cách giữa các lặp lại chuỗi để ước lượng độ dài khoá.

Friedman test (index of coincidence) để ước lượng độ dài khoá.

Sau khi biết độ dài m, tách văn bản thành m dãy (mỗi dãy là Caesar) và dùng phân tích tần suất cho từng dãy để tìm dịch shift.

# kết quả 
<img width="1919" height="834" alt="image" src="https://github.com/user-attachments/assets/5fa00578-908f-4158-8bb4-bc395168c10c" />


# Playfair cipher
Tên gọi

Playfair — cipher ma trận 5x5, mã hoá theo cặp (digraphs). Thường ghép J vào I hoặc loại J.

# Thuật toán

Tạo ma trận 5x5 từ khoá: ghi khóa không lặp ký tự hàng ngang, sau đó điền phần còn lại của bảng chữ cái (thường bỏ J).

Tiền xử lý plaintext:

Loại khoảng trắng, chuyển hoa, thay J->I.

Tách thành cặp ký tự. Nếu cặp hai ký tự giống nhau, chèn 'X' giữa.

Nếu cuối cùng lẻ, thêm 'X'.

Mã hoá mỗi cặp (a,b):

Nếu cùng hàng: thay bằng ký tự bên phải (vòng tròn).

Nếu cùng cột: thay bằng ký tự dưới (vòng tròn).

Nếu khác hàng và cột: thay bằng ký tự cùng hàng của ký tự đầu, cột của ký tự thứ hai (và ngược lại).

Giải mã: tương tự nhưng dịch trái/trên.

Không gian khóa

Khoá là bất kỳ chuỗi ký tự — không gian lớn, nhưng Playfair dễ bị phân tích nếu văn bản dài.

Cách phá mã (không cần khoá)

Tấn công bằng băm tần suất digram (2-gram): Playfair phá bằng cách tối ưu hoá bảng 5x5 để tối đa hoá phù hợp tần suất bigram tiếng Anh (heuristic hoặc hill-climbing).

Brute force toàn bộ ma trận là rất lớn (25! / ?), không khả thi.

Known-plaintext tấn công có thể dẫn đến ma trận.

# kết quả 
<img width="1919" height="885" alt="image" src="https://github.com/user-attachments/assets/2727ed89-04b3-4634-a93f-7fa97c90b8c6" />

