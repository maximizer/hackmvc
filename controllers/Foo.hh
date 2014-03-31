<?hh

class Foo extends Controller
{
    public function index() : void {
        $data = new Map<string, mixed>();
        $data["foo"] = $this->GETParams()->get("foo");

        $this->renderView('index/index.tpl.hh', $data);        
    }
    
}