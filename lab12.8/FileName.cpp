#include <iostream>
#include <string>

struct Train {
    int number;
    std::string arrivalTime;
    int platform;
    Train* next;
    Train* prev;

    Train(int _number, const std::string& _arrivalTime) : number(_number), arrivalTime(_arrivalTime), platform(-1), next(nullptr), prev(nullptr) {}
};

class TrainStation {
private:
    Train* head;
    Train* tail;

public:
    Train* getFirstTrain() const { return head; }

    TrainStation() : head(nullptr), tail(nullptr) {}

    void addTrain(int number, const std::string& arrivalTime) {
        Train* newTrain = new Train(number, arrivalTime);
        if (!head) {
            head = tail = newTrain;
        }
        else {
            tail->next = newTrain;
            newTrain->prev = tail;
            tail = newTrain;
        }
    }

    void printTrains() const {
        Train* current = head;
        while (current) {
            std::cout << "Train Number: " << current->number << ", Arrival Time: " << current->arrivalTime << std::endl;
            current = current->next;
        }
    }

    void findTrainsByTime(const std::string& startTime, const std::string& endTime) {
        TrainStation newStation;
        Train* current = head;
        while (current) {
            if (current->arrivalTime >= startTime && current->arrivalTime <= endTime) {
                newStation.addTrain(current->number, current->arrivalTime);
            }
            current = current->next;
        }
        std::cout << "\nTrains arriving between " << startTime << " and " << endTime << ":" << std::endl;
        newStation.printTrains();
    }
};

int main() {
    TrainStation station;
    station.addTrain(101, "08:00");
    station.addTrain(102, "09:30");
    station.addTrain(103, "10:45");
    station.addTrain(104, "12:15");
    station.addTrain(105, "14:00");

    std::cout << "All Trains:" << std::endl;
    station.printTrains();

    std::string startTime = "09:00";
    std::string endTime = "12:00";
    station.findTrainsByTime(startTime, endTime);

    return 0;
}
