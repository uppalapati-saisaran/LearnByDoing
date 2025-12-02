import os 
from utils import normalize_line 
""""
Replace the entire old content with this final improved version.
why overwrite?
- Because this updated version includes.
  - Advanced error handling
  - generator based log streaming.
  - integration with utils.normalize_line 
  - clean class-based structure 
"""

class LogReader:
    def __init__(self,file_path: str):
        self.file_path = file_path 

    def exists(self) -> bool:
        """Check if the file exists before reading"""
        return os.path.exists(self.file_path)

    def read_logs(self):
        if not self.exists():
            print(f"[ERROR] File not found: {self.file_path}")
            return 

        try:
            with open(self.file_path,"r") as f:
                for line in f:
                    yield normalize_line(line) 
        except PermissionError:
            print(f"[ERROR] Permission denied: {self.file_path}")
        except Exception as e:
            print(f"[ERROR] Unexcepted issue while reading logs: {e}")

