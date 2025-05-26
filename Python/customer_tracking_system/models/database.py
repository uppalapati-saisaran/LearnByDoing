import sqlite3 

DB_NAME = "ticket.db"

def get_connection():
    return sqlite3.connect(DB_NAME)

def setup_database():
    with get_connection() as conn:
        cursor = conn.cursor()
        cursor.execute('''
                       CREATE TABLE IF NOT EXISTS customers (
                           id INTEGER PRIMARY KEY AUTOINCREMENT,
                           name TEXT NOT NULL,
                           email TEXT NOT NULL  UNIQUE
                       )
                       ''')
        
        cursor.execute('''
                       CREATE TABLE IF NOT EXISTS tickets(
                           id INTEGER PRIMARY KEY AUTOINCREMENT,
                           title TEXT NOT NULL,
                           description TEXT,
                           status TEXT DEFAULT 'Open',
                           created_at TEXT DEFAULT CURRENT_TIMESTAMP,
                           customer_id INTEGER,
                           FOREIGN KEY(customer_id) REFERENCES customers(id)
                       )
                       ''')
        conn.commit()