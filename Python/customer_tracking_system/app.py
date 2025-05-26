from models.database import setup_database 
from services import ticket_service 


def menu():
    print("\n-- Customer Ticket System ---")
    print("1. Create Ticket")
    print("2. List Tickets")
    print("3. Update Ticket Status")
    print("4. Exit")

def main():
    setup_database()
    while True:
        menu()
        choice = input("Choose option: ")
        if choice == '1':
            name = input("Name : ")
            email = input("Email")
            title = input("Ticket Title")
            desc = input("Description: ")
            ticket_service.create_new_tickets(name, email, title,desc) 

        elif choice == "2":
            tickets = ticket_service.get_all_tickets()
            for t in tickets:
                print(f"[{t[0]}] {t[1]} | Status: {t[2]} | Date : {t[3]} | Customer: {t[4]} ")
        
        elif choice == "3":
            ticket_id = int(input("Ticket ID:"))
            new_status = input("New Status (Open/InProgress/Closed):")
            ticket_service.change_ticket_status(ticket_id,new_status) 
       
        elif choice == "4":
             break 
        else:
            print("Invalid choice!")

if __name__ == "__main__":
    main() 


