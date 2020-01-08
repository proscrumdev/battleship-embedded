#include <Position.h>
#include <sstream>
namespace std {
    template<typename T>
    std::string to_string(const T &n) {
        std::ostringstream s;
        s << n;
        return s.str();
    }
}

enum Letters Column;
int Row;

Position::Position() {

}

Position::Position(Letters column, int row) {
        Column = column;
        Row = row;
}

string Position::toString() {
        char letter = Column + 'A';
        return letter + std::to_string(Row);
}
