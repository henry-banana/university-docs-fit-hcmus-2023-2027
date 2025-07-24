#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>    
#include <sstream>     
#include <iomanip>     
#include <numeric>     
#include <algorithm>    

enum class ErrorCode {
    UnknownError = 1000,
    ArgumentNull = 1001,
    InvalidSize = 1002,
    FileNotFound = 1003,
    FolderNotFound = 1004,
    DuplicateName = 1005,
    InvalidAttributeChange = 1006,
    ArgumentEmpty = 1007,
    ItemNotFound = 1008
};

// Custom exception class
class MyException : public std::runtime_error {
private:
    std::string _errorDescription;
    ErrorCode _errorCode;

    static std::string BuildErrorMessage(const ErrorCode& errCode, const std::string& errDes) {
        std::ostringstream oss;
        oss << errDes << " (Code: " << static_cast<int>(errCode) << ")";
        return oss.str();
    }

public:
    MyException(const ErrorCode& errCode, const std::string& errDes)
        : std::runtime_error(BuildErrorMessage(errCode, errDes)),
          _errorCode(errCode),
          _errorDescription(errDes) {}

    const std::string& GetErrorDescription() const { return _errorDescription; }
    const ErrorCode& GetErrorCode() const { return _errorCode; }
};

class CItem {
protected:
    std::string _name;
    bool _isHidden; // Thuộc tính hidden

public:
    // Destructor ảo để đảm bảo giải phóng bộ nhớ đúng cách cho các lớp con
    virtual ~CItem() = default;

    CItem(const std::string& name) : _isHidden(false) { // Mặc định không ẩn
        if (name.empty()) {
            throw MyException(ErrorCode::ArgumentEmpty, "Item name cannot be empty");
        }
        _name = name;
    }

    // Phương thức ảo thuần túy để tính kích thước
    virtual float Size() const = 0;
    std::string Name() const { return _name; }

    bool IsHidden() const { return _isHidden; }

    // SetHidden là virtual vì hành vi có thể khác giữa File và Folder
    virtual void SetHidden(const bool& isHidden, const bool& isAlsoApplyToChildren) {
        _isHidden = isHidden;
    }

    virtual void Print(const bool& isPrintHiddenItems, int indent = 0) const = 0;
};

class CFolder : public CItem {
private:
    std::vector<CItem*> _children; // Chứa con trỏ tới các CItem con

public:
    CFolder(const std::string& name) : CItem(name) {}

    // Destructor để giải phóng bộ nhớ của các item con
    ~CFolder() override {
        for (CItem* child : _children) {
            delete child;
        }
        _children.clear();
    }

    void Print(const bool& isPrintHiddenItems, int indent = 0) const override {
        if (!isPrintHiddenItems && _isHidden) { // Nếu ẩn và không in item ẩn thì không làm gì
            return;
        }
        
        std::cout << std::string(indent, ' ') << "[" << _name << "]" 
                  << " (" << std::fixed << std::setprecision(3) << Size() << " B)"
                  << (IsHidden() ? " (Hidden)" : "") << "\n";
        
        for (CItem* child : _children) {
            child->Print(isPrintHiddenItems, indent + 2); // Đệ quy in các item con
        }
    }

    void Add(CItem* item) {
        if (item == nullptr) {
            throw MyException(ErrorCode::ArgumentNull, "Argument 'item' must not be null.");
        }
        
        // Kiểm tra trùng tên trong cùng một cấp
        for (const CItem* existingItem : _children) {
            if (existingItem->Name() == item->Name()) {
                throw MyException(ErrorCode::DuplicateName, 
                    "Item with name '" + item->Name() + "' already exists in folder '" + _name + "'.");
            }
        }
        _children.push_back(item);
    }

    float Size() const override {
        float total = 0;
        for (const CItem* item : _children) {
            total += item->Size();
        }
        return total;
    }

    CItem* FindByName(const std::string& name) {
        // Tìm kiếm trong cấp con trực tiếp trước
        for (CItem* item : _children) {
            if (item->Name() == name) {
                return item;
            }
        }

        // Tìm kiếm đệ quy trong các thư mục con
        for (CItem* item : _children) {
            CFolder* folder = dynamic_cast<CFolder*>(item);
            if (folder != nullptr) {
                CItem* found = folder->FindByName(name);
                if (found != nullptr) {
                    return found;
                }
            }
        }
        return nullptr;
    }

    CItem* RemoveByName(const std::string& name) {
        // Tìm và xóa trong cấp con trực tiếp
        for (auto it = _children.begin(); it != _children.end(); ++it) {
            if ((*it)->Name() == name) {
                CItem* itemToRemove = *it;
                _children.erase(it);
                return itemToRemove; // Trả về con trỏ, caller chịu trách nhiệm giải phóng
            }
        }

        // Tìm và xóa đệ quy trong các thư mục con
        for (CItem* item : _children) {
            CFolder* folder = dynamic_cast<CFolder*>(item);
            if (folder != nullptr) {
                CItem* removed = folder->RemoveByName(name);
                if (removed != nullptr) {
                    return removed;
                }
            }
        }
        return nullptr; // Không tìm thấy item để xóa
    }

    void SetHidden(const bool& isHidden, const bool& isAlsoApplyToChildren) override {
        CItem::SetHidden(isHidden, isAlsoApplyToChildren); // Gọi SetHidden của lớp cha để đặt thuộc tính cho folder hiện tại

        if (isAlsoApplyToChildren) {
            // Áp dụng đệ quy cho tất cả các item con (files và folders)
            for (CItem* item : _children) {
                item->SetHidden(isHidden, isAlsoApplyToChildren); 
            }
        }
    }
};

class CFile : public CItem {
private:
    float _size;

public:
    CFile(const std::string& name, const float& size) : CItem(name) {
        if (size < 0) {
            throw MyException(ErrorCode::InvalidSize, "File size cannot be negative.");
        }
        _size = size;
    }

    void Print(const bool& isPrintHiddenItems, int indent = 0) const override {
        if (!isPrintHiddenItems && _isHidden) { // Nếu ẩn và không in item ẩn thì không làm gì
            return;
        }
        std::cout << std::string(indent, ' ') << _name 
                  << " (" << std::fixed << std::setprecision(3) << _size << " B)"
                  << (IsHidden() ? " (Hidden)" : "") << "\n";
    }

    float Size() const override { return _size; }

    // CFile cũng cần override SetHidden, mặc dù nó không cần isAlsoApplyToChildren
    void SetHidden(const bool& isHidden, const bool& isAlsoApplyToChildren) override {
        CItem::SetHidden(isHidden, isAlsoApplyToChildren); // Chỉ đặt thuộc tính cho file hiện tại
    }
};

int main() {
    try {
        CFolder C("C");
        CFolder System("System");
        CFolder Windows("Windows");
        CFile a_txt("a.txt", 123);
        CFile b_doc("b.doc", 456);

        System.Add(&a_txt);
        Windows.Add(&b_doc);
        C.Add(&System);
        C.Add(&Windows);

        std::cout << "\nContent of folder C ->\n";
        bool isPrintHiddenItems = false;
        C.Print(isPrintHiddenItems);

        CItem* p = C.RemoveByName("System");
        std::cout << "\n\nContent of folder C after removing folder System ->\n";
        C.Print(isPrintHiddenItems);

        std::cout << "\n\n";
        std::string itemToFind = "b.doc";
        p = C.FindByName(itemToFind);
        if (p) {
            std::cout << itemToFind << " is found in folder C\n";
        } else {
            std::cout << itemToFind << " isn't found\n";
        }

        itemToFind = "a.txt";
        p = C.FindByName(itemToFind);
        if (p) {
            std::cout << itemToFind << " is found in folder C\n\n";
        } else {
            std::cout << itemToFind << " isn't found\n\n";
        }

        itemToFind = "Windows";
        p = C.FindByName(itemToFind);
        bool isHidden = false;
        bool isAlsoApplyToChildren = false;

        if (p) {
            std::cout << itemToFind << " is found in folder C\n";
            std::cout << "Content of folder " << itemToFind << "->\n";
            
            isHidden = true, isAlsoApplyToChildren = false;
            p->SetHidden(isHidden, isAlsoApplyToChildren);
            p->Print(false);

            isHidden = true, isAlsoApplyToChildren = true;
            p->SetHidden(isHidden, isAlsoApplyToChildren);
            p->Print(false);
        } else {
            std::cout << itemToFind << " isn't found\n";
        }
    } catch (const MyException& e) {
        std::cout << "Custom Error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Standard Error: " << e.what() << std::endl;
    }

    return 0;
}