#ifndef GOATENGINE_FOREIGNKEY_HPP
#define GOATENGINE_FOREIGNKEY_HPP

#include <string>

namespace Engine {
    class ForeignKey {
        public:
            ForeignKey(std::string foreignKeyName, std::string referenceTable, std::string referenceName);
            [[nodiscard]] std::string getForeignKeyName() const;
            [[nodiscard]] std::string getReferenceTable() const;
            [[nodiscard]] std::string getReferenceName() const;
        private:
            std::string _foreignKeyName;
            std::string _referenceTable;
            std::string _referenceName;
    };
}

#endif //GOATENGINE_FOREIGNKEY_HPP
