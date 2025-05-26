from models import customer,ticket

def create_new_tickets(name,email,title,description):
    cust = customer.get_customer_by_email(email) 
    
    if not cust:
        customer_id = customer.add_customer(name,email)
    else:
        customer_id = cust[0] 

    ticket.create_ticket(title,description,customer_id)


def get_all_tickets():
    return ticket.list_tickets()

def change_ticket_status(ticket_id,new_status):
    ticket.update_ticket_status(ticket_id,new_status)


    