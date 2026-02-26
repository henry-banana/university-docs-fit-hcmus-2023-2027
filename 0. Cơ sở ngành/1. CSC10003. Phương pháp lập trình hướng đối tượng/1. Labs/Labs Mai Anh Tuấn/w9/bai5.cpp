#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Directory;

class FileSystemNode {
protected:
    std::string name;

public:
    FileSystemNode(const std::string& n) : name(n) {}
    virtual ~FileSystemNode() {}

    virtual unsigned long long getSize() const = 0;
    virtual void display(int depth) const = 0;
    virtual void countItems(int& fileCount, int& dirCount) const = 0;
    virtual bool isDirectory() const = 0;
    std::string getName() const { return name; }

    virtual FileSystemNode* findNode(const std::string& nodeName) {
        if (this->name == nodeName) {
            return this;
        }
        return nullptr;
    }
};

class File : public FileSystemNode {
private:
    unsigned long long size;

public:
    File(const std::string& n, unsigned long long s) : FileSystemNode(n), size(s) {}

    unsigned long long getSize() const override {
        return size;
    }

    void display(int depth) const override {
        for (int i = 0; i < depth; ++i) std::cout << "  "; 
        std::cout << name << " (" << size << " B)\n";
    }

    void countItems(int& fileCount, int& dirCount) const override {
        fileCount++;
    }

    bool isDirectory() const override {
        return false;
    }
};

class Directory : public FileSystemNode {
private:
    std::vector<FileSystemNode*> children;

public:
    Directory(const std::string& n) : FileSystemNode(n) {}

    ~Directory() override {
        for (FileSystemNode* child : children) {
            delete child;
        }
        children.clear();
    }

    void add(FileSystemNode* newNode) {
        if (!newNode) {
            return; 
        }

        for (const FileSystemNode* existingChild : children) {
            if (existingChild->getName() == newNode->getName()) {
                std::cerr << "CANH BAO: Muc '" << newNode->getName()
                          << "' da ton tai trong thu muc '" << this->name
                          << "'. Khong them ban sao.\n";
                delete newNode;
                return;
            }
        }
        children.push_back(newNode);
    }

    unsigned long long getSize() const override {
        unsigned long long totalSize = 0;
        for (const FileSystemNode* child : children) {
            totalSize += child->getSize();
        }
        return totalSize;
    }

    void display(int depth) const override {
        for (int i = 0; i < depth; ++i) std::cout << "  ";
        std::cout << "[" << name << "]\n";
        for (const FileSystemNode* child : children) {
            child->display(depth + 1);
        }
    }

    void countItems(int& fileCount, int& dirCount) const override {
        for (const FileSystemNode* child : children) {
            if (child->isDirectory()) {
                dirCount++;
            } else {
                fileCount++;
            }
        }
    }
    
    void countDescendants(int& fileCount, int& dirCount) const {
        for (const FileSystemNode* child : children) {
            if (child->isDirectory()) {
                dirCount++;
                ((Directory*)child)->countDescendants(fileCount, dirCount);
            } else {
                fileCount++;
            }
        }
    }


    bool isDirectory() const override {
        return true;
    }

    FileSystemNode* findNode(const std::string& nodeName) override {
        if (this->name == nodeName) {
            return this;
        }
        for (FileSystemNode* child : children) {
            FileSystemNode* found = child->findNode(nodeName);
            if (found) {
                return found;
            }
        }
        return nullptr;
    }
};

std::string formatSize(unsigned long long size) {
    std::string s = std::to_string(size);
    int n = s.length() - 3;
    while (n > 0) {
        s.insert(n, ".");
        n -= 3;
    }
    return s;
}


int main() {
    // 1. Tạo một cây thư mục tập tin như bên dưới.
    Directory* root = new Directory("C:");

    Directory* baiTap = new Directory("Bai tap");
    baiTap->add(new File("BT1.doc", 123456));

    Directory* baiTapC = new Directory("Bai tap C");
    baiTapC->add(new File("BT2.cpp", 1280));
    baiTapC->add(new File("BT2.xls", 23456));

    baiTap->add(baiTapC);

    Directory* lyThuyet = new Directory("Ly thuyet");
    lyThuyet->add(new File("Ch1.ppt", 34567));

    root->add(baiTap);
    root->add(lyThuyet);

    // 2. Xuất cây thư mục từ thư mục gốc.
    std::cout << "--- Cay thu muc ---\n";
    root->display(0);
    std::cout << "--------------------\n\n";

    // 3. Đếm số tập tin và thư mục có trong một thư mục nào đó.
    std::string targetDirNameCount = "Bai tap";
    FileSystemNode* dirToCountNode = root->findNode(targetDirNameCount);

    if (dirToCountNode && dirToCountNode->isDirectory()) {
        Directory* dirToCount = static_cast<Directory*>(dirToCountNode);
        int fileCount = 0;
        int dirCount = 0;
        dirToCount->countDescendants(fileCount, dirCount);

        std::cout << "Trong thu muc [" << targetDirNameCount << "]:\n";
        std::cout << "  - So tap tin: " << fileCount << "\n";
        std::cout << "  - So thu muc con: " << dirCount << "\n";
    } else {
        std::cout << "Khong tim thay thu muc [" << targetDirNameCount << "] de dem.\n";
    }
    std::cout << "\n";
    
    targetDirNameCount = "C:";
    dirToCountNode = root->findNode(targetDirNameCount);
     if (dirToCountNode && dirToCountNode->isDirectory()) {
        Directory* dirToCount = static_cast<Directory*>(dirToCountNode);
        int fileCount = 0;
        int dirCount = 0;
        dirToCount->countDescendants(fileCount, dirCount);
        std::cout << "Trong thu muc [" << targetDirNameCount << "] (bao gom cac thu muc con):\n";
        std::cout << "  - So tap tin: " << fileCount << "\n";
        std::cout << "  - So thu muc con: " << dirCount << "\n";
    } else {
        std::cout << "Khong tim thay thu muc [" << targetDirNameCount << "] de dem.\n";
    }
    std::cout << "\n";

    // 4. Tính kích thước một thư mục có tên cho trước.
    std::string targetDirNameSize = "Bai tap";
    FileSystemNode* dirToSizeNode = root->findNode(targetDirNameSize);

    if (dirToSizeNode) {
        unsigned long long totalSize = dirToSizeNode->getSize();
        std::cout << "Kich thuoc cua '" << targetDirNameSize << "': "
                  << formatSize(totalSize) << " B\n";
    } else {
        std::cout << "Khong tim thay '" << targetDirNameSize << "' de tinh kich thuoc.\n";
    }
    std::cout << "\n";

    targetDirNameSize = "C:";
    dirToSizeNode = root->findNode(targetDirNameSize);
     if (dirToSizeNode) {
        unsigned long long totalSize = dirToSizeNode->getSize();
        std::cout << "Kich thuoc cua '" << targetDirNameSize << "': "
                  << formatSize(totalSize) << " B\n";
    } else {
        std::cout << "Khong tim thay '" << targetDirNameSize << "' de tinh kich thuoc.\n";
    }

    delete root;

    return 0;
}