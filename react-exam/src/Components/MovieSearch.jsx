import { Link } from "react-router-dom"

const MovieSearch = () => {
  return (
    <div>
      <div className="container">
          <div className="d-flex gap-4">
          <Link to={"/moviedetails"}>Movie Details</Link>
          <Link to={"/movielist"}>Back</Link>
        </div>
      </div>
    </div>
  )
}

export default MovieSearch