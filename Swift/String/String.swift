import Foundation

extension String {

    subscript(_ i: Int) -> String {
        let index = self.index(self.startIndex, offsetBy: i)
        return String(self[index])
    }
}