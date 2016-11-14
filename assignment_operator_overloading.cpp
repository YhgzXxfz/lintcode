class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = nullptr;
    }
    Solution(char *p_data) {
        this->m_pData = p_data;
    }

    // Implement an assignment operator
    Solution operator=(const Solution& object) {
        // write your code here
        if (this != &object) {
            char* new_pData = nullptr;
            if (object.m_pData) {
                size_t count = strlen(object.m_pData);
                new_pData = new char[count];
                copy(object.m_pData, object.m_pData + count, new_pData);
            }
            if (m_pData) delete []m_pData;
            m_pData = new_pData;
        }
        return *this;
    }
};

