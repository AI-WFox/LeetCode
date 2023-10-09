class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Bắt đầu từ phần tử cuối cùng (least significant digit)
        for (int i = n - 1; i >= 0; i--) {
            // Tăng giá trị của phần tử cuối cùng lên 1
            digits[i]++;
            
            // Nếu giá trị vượt quá 9, thì ta phải xử lý trường hợp cộng dồn
            if (digits[i] > 9) {
                digits[i] = 0; // Đặt giá trị hiện tại thành 0
            } else {
                // Nếu giá trị không vượt quá 9, thì không cần xử lý nữa và có thể trả về kết quả
                return digits;
            }
        }
        
        // Nếu chương trình thực hiện tới đây, tức là tất cả các phần tử đều vượt quá 9,
        // nên ta thêm một số 1 vào đầu mảng để tạo ra kết quả cuối cùng
        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};

