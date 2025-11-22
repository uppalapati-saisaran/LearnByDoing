from logger import setup_logger
from downloader import FileDownloader

def main():
    logger = setup_logger()
    logger.info("MAIN STARTED")
    downloader = FileDownloader()
    logger.info("Download object created")
    downloader.run()
    logger.info("Run method finished")

if __name__ == "__main__":
    main()
