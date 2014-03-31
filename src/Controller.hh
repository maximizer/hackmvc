<?hh
class Controller
{
    private Map <string, mixed> $data;

    public function GETParams() : Map<string, mixed> {
        return Map::fromArray($_GET);
    }

    public function POSTParams() : Map<string, mixed> {
        return Map::fromArray($_POST);
    }

    public function renderView(string $viewPath, Map<string, mixed> $data) : void {
        $this->data = $data;
        require __DIR__ . '/../views/' . $viewPath;
    }
}
